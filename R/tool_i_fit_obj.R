#' Subset object even if index is out of range
#'
#' @param i number to make sure to fit into index range
#' @param obj object to subset data from 
#'
#' @return elements of object circularly indexed by  mapping i to range of 1 to size of object
#' 
#' @export
#'
#' @examples
#' 
#' tool_i_fit_obj(-2:6, 3)
#' 
#' @seealso \link{tool_i_fit_index}
#' 
tool_i_fit_obj <- function(i, obj){
  obj[tool_i_fit_index(i, length(obj))]
}