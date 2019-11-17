
#include <Rcpp.h>
using namespace Rcpp;

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

// [[Rcpp::plugins(cpp11)]]



// define Node
struct Node {
  set<int> linked_nodes;
  set<int> vector_positions;
  bool visited = false;
  int subgraph_id = 0;
};




//' Finding and indexing subgraphs in undirected graph 
//' 
//' Finding and indexing subgraphs in undirected graph.
//' 
//' Input is given as two vectors where each pair of node ids `id_1[i]` - `id_2[i]` indicates an 
//' edge between two nodes. 
//' 
//' @param id_1 vector of integers indicating ids 
//' @param id_2 vector of integers indicating ids 
//' @param verbose in integer indicating the amount of verbosity; good for long running tasks or to 
//'   get more infoamtion about the workings of the algorithm; currently accepted values: 0, 1, 2
//' 
//' @return An integer vector with subgraph ids such that each distinct subgraph - i.e. all 
//'   nodes are reachable within the graph and no node outside the subgraph is reachable - 
//'   gets a distinct integer value. Integer values are assigned via 
//'
//' @examples
//' 
//' graphs_find_subgraphs(c(1,2,1,5,6,6), c(2,3,3,4,5,4), verbose = 0)
//' graphs_find_subgraphs(c(1,2,1,5,6,6), c(2,3,3,4,5,4), verbose = 2)
//'
//' @export
//' 
// [[Rcpp::export]]
IntegerVector graphs_find_subgraphs(IntegerVector id_1, IntegerVector id_2, int verbose = 2) {
  
  // check inputs 
  if ( id_2.length() != id_1.length() ){
    throw std::range_error("length(id_1) != length(id_2)");
  }

  
  // initialize result vector
  IntegerVector sub_graph_id(id_1.length(), NA_INTEGER);

  // initialize max id 
  int graph_max_id = 1;
  
  // initialize list of nodes mapping to a group
  map<int, Node> map_nodes;
  
  // build dictionary of all nodes 
  if (verbose >= 1 ){ Rcout << "\nBuilding dictionary.\n"; }
  for ( int i = 0; i < sub_graph_id.length(); i++ ) {
    
    if ( (i) % 10000 == 0 ) {
      Rcpp::checkUserInterrupt();
      if (verbose >= 1 ){ Rcout << "\r" << i << "                     ";}
    }
    
    Node e;
    Node ee;
    
    map_nodes[id_1[i]] = e;
    map_nodes[id_2[i]] = ee;
  }
  
  
  // add linked node ids and node positions to mapping
  if (verbose >= 1 ){ Rcout << "\nCollecting nodes and edges.\n"; }
  for ( int i = 0; i < sub_graph_id.length(); i++ ) {

    if ( (i) % 10000 == 0 ) {
      Rcpp::checkUserInterrupt();
      if (verbose >= 1 ){ Rcout << "\r" << i   << "                     "; }
    }
    
    if ( id_1[i] != id_2[i] ){
      map_nodes[id_1[i]].linked_nodes.insert(id_2[i]);
      map_nodes[id_2[i]].linked_nodes.insert(id_1[i]);
    }

    map_nodes[id_1[i]].vector_positions.insert(i);
    map_nodes[id_2[i]].vector_positions.insert(i);

  }

  
  // loop over all nodes and assign groups 
  if (verbose >= 1 ){ Rcout << "\nSearching for subgraphs.\n"; }
  int i = 0; 
  map<int, Node>::iterator it = map_nodes.begin();
  
  while (it != map_nodes.end()) {
    
    // key from current mapping 
    int key = it->first;
    
    // value from current mapping
    Node value = it->second;
    
    
    // logging and checking for user interupt
    if ( (i) % 10000 == 0 ) {
      Rcpp::checkUserInterrupt();
      if (verbose >= 1 ){ Rcout << "\r" << i << "                     "; }
    }

    
    // logging     
    if (verbose >= 1 ){ Rcout << "node " << key << " - vis " << value.visited << " - subid " << graph_max_id ;}
    
    // search through unprocessed nodes
    if ( value.visited == false ){

      if ( verbose >= 2){ Rcout << " processing ";}
      
      //
      set<int> visited;
      vector<int> stack;
      
      for ( auto node_id : value.linked_nodes ) {
        stack.push_back(node_id);
      }
      

      // go through all children
      while ( !stack.empty() ) {
        
        int node_id = stack.back();
        stack.pop_back();
        map_nodes.find(node_id)->second.visited = true;
        
        for ( int pos : map_nodes.find(node_id)->second.vector_positions ){
          sub_graph_id[pos] = graph_max_id;
        }
        
        if (verbose >= 2 ){ Rcout << node_id << " "; }
      }
      
      // step up graph counter
      graph_max_id++;
      
    } else {
      // go to next node
    }
    
    if (verbose >= 1 ){ Rcout << "\n"; }
    // update indices and iterators
    i++;
    it++;
    
  }
  
  // ensure to move to next line for next printing
  if (verbose >= 1 ){ Rcout << "\n"; }
  
  
  return sub_graph_id;
}
