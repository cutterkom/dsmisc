#' Fit number into length of index
#'
#' @param i number to make sure to fit into index range
#' @param index size of index
#'
#' @return number that fits into index by circularly mapping i to range of 1 to size of index
#' 
#' @export
#'
#' @examples
#' 
#' tool_i_fit_index(-2:6, 3)
#' 
#' @seealso \link{tool_i_fit_obj}
#' 
tool_i_fit_index <- function(i, index){
  tmp <- (i %% index)
  ifelse(tmp == 0, index, tmp)
}