#' web_gen_param_list_exapnd
#' 
#' Generate an url parameter combination from sets of parameter values.
#'
#' @param ... 
#' @param sep_1 se
#' @param sep_2 
#'
#' @export
#'
#' @examples
#' 
#' web_gen_param_list_exapnd(q = "beluga", lang = c("de", "en"))
#' 
web_gen_param_list_exapnd <- 
  function(..., sep_1 = "=", sep_2 = "&"){
    
    # handling edge cases
    lst <- list(...)
    lst <- 
      lapply(
        lst, 
        function(x){
          if ( length(x)==0 ){
            x <- ""
          }
          x
        }
      )
    
    # make combinations
    df <- expand.grid(lst)
    
    # concatenation 1
    for(i in seq_along(df)){
      concat  <- paste0(names(df)[i], sep_1, as.character(df[[i]]))
      df[[i]] <- concat
    }
    
    # concatenation 2
    df <- apply(df, 1, paste0, collapse = sep_2)
    
    # return
    unlist(df)
  }