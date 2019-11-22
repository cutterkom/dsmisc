
<!-- README.md is generated from README.Rmd. Please edit that file -->

<!-- -->

<!-- FILL OUT OPTIONS !!! -->

<!-- -->

<!-- -->

<!-- -->

# Data Science Box of Pandora Miscellaneous

**Status**

<a href="https://travis-ci.org/petermeissner/dsmisc"><img src="https://api.travis-ci.org/petermeissner/dsmisc.svg?branch=master"><a/>
[![AppVeyor build
status](https://ci.appveyor.com/api/projects/status/github/petermeissner/dsmisc?branch=master&svg=true)](https://ci.appveyor.com/project/petermeissner/dsmisc)
<a href="https://codecov.io/gh/petermeissner/dsmisc"><img src="https://codecov.io/gh/petermeissner/dsmisc/branch/master/graph/badge.svg" alt="Codecov" /></a>
<a href="https://cran.r-project.org/package=dsmisc">
<img src="http://www.r-pkg.org/badges/version/dsmisc"> </a>
<img src="http://cranlogs.r-pkg.org/badges/grand-total/dsmisc">
<img src="http://cranlogs.r-pkg.org/badges/dsmisc">

*lines of R code:* 4, *lines of test code:* 24

**Version**

0.1.3 ( 2019-11-22 21:10:15 )

**Description**

Tool collection for common and not so common data science use cases.
This includes custom made algorithms for data management as well as
value calculations that are hard to find elsewhere because of their
specificity but would be a waste to get lost nonetheless.

**License**

GPL (\>= 2) <br>Peter Meissner \[aut,
cre\]

**Citation**

``` r
citation("dsmisc")
```

``` r
Meissner P (2019). dsmisc: Data Science Box of Pandora Miscellaneous. R package version 0.1.3.
```

**BibTex for citing**

``` r
toBibtex(citation("dsmisc"))
```

    @Manual{,
      title = {dsmisc: Data Science Box of Pandora Miscellaneous},
      author = {Peter Meissner},
      year = {2019},
      note = {R package version 0.1.3},
    }

**Installation**

Stable version from CRAN:

``` r
install.packages("dsmisc")
```

<!-- Latest development version from Github: -->

<!-- ```{r, eval=FALSE} -->

<!-- devtools::install_github("user_name/repo_name") -->

<!-- ``` -->

## Usage

*starting up …*

``` r
library("dsmisc")
```

### Graph computations

*find isolated graphs / networks*

A graph described by an edgelist with two distinct subgraphs.

``` r
edges_df <- 
  data.frame(
    node_1 = c(1:5, 10:8),
    node_2 = c(2:6, 7,7,7)
  )

edges_df
```

    ##   node_1 node_2
    ## 1      1      2
    ## 2      2      3
    ## 3      3      4
    ## 4      4      5
    ## 5      5      6
    ## 6     10      7
    ## 7      9      7
    ## 8      8      7

Finding subgraphs and grouping them together via subgraph id.

``` r
edges_df$subgraph_id <- 
  graphs_find_subgraphs(
    id_1    = edges_df$node_1,
    id_2    = edges_df$node_2,
    verbose = 0
  )

edges_df
```

    ##   node_1 node_2 subgraph_id
    ## 1      1      2           1
    ## 2      2      3           1
    ## 3      3      4           1
    ## 4      4      5           1
    ## 5      5      6           1
    ## 6     10      7           2
    ## 7      9      7           2
    ## 8      8      7           2

*speedtest for large graph*

``` r
edges_df <- 
   data.frame(
    node_1 = sample(x = 1:10000, size = 10^5, replace = TRUE),
    node_2 = sample(x = 1:10000, size = 10^5, replace = TRUE)
  )

system.time({
  edges_df$subgraph_id <- 
    graphs_find_subgraphs(
      id_1    = edges_df$node_1,
      id_2    = edges_df$node_2,
      verbose = 0
    )
})
```

    ##    user  system elapsed 
    ##    1.27    0.02    1.28
