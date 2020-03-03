#' stats_modus_multi
#'
#'
#' @inheritParams stats_modus
#'
#' @return return vector with 
#' @export
#'
stats_modus_multi <- 
  function(x){
    x_unique <- unique(x)
    tab_x    <- tabulate(match(x, x_unique))
    x_unique[which(tab_x==max(tab_x))]
  }
