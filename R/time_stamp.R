#' time_stamp
#' 
#' Generating file name ready iso time stamps.
#' 
#' @param ts one or many POSIX time stamp
#' @param sep separators to be used for formatting
#'
#' @export
#'
#' @examples
#' 
#' time_stamp()
#' time_stamp( Sys.time() - 10000 )
#' 
time_stamp <- 
  function( ts = Sys.time(), sep = c("-", "_", "_")){
    
    # process parameter
    if ( length(sep) < 3){
      sep <- rep(sep, 3)
    }
    
    # execute formatting
    format(
      ts, 
      format = 
        paste0(
          "%Y", sep[1], "%m", sep[1], "%d", 
          sep[2], 
          "%H", sep[3], "%M", sep[3], "%S"
        )
    )
  }