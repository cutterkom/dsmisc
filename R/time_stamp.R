#' time_stamp
#'
#' @param ts one or many POSIX timestamp
#'
#' @export
#'
#' @examples
#' 
#' time_stamp()
#' time_stamp( Sys.time() - 10000 )
#' 
time_stamp <- 
  function( ts = Sys.time()){
    format(ts, format = "%Y-%m-%d_%H_%M_%S")
  }