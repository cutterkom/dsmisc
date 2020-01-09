
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

*lines of R code:* 16, *lines of test code:* 24

**Version**

0.2.0 ( 2020-01-09 21:14:00 )

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
Meissner P (2020). dsmisc: Data Science Box of Pandora Miscellaneous. R package version 0.2.0.
```

**BibTex for citing**

``` r
toBibtex(citation("dsmisc"))
```

    @Manual{,
      title = {dsmisc: Data Science Box of Pandora Miscellaneous},
      author = {Peter Meissner},
      year = {2020},
      note = {R package version 0.2.0},
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
    ##    1.44    0.02    1.45

### String Functions

Stringr/stringi is cool but … can it do this?

**Extract specific RegEx groups**

``` r
strings <- paste(LETTERS, seq_along(LETTERS), sep = "_")

# whole pattern
str_group_extract(strings, "([\\w])_(\\d+)")
```

    ##  [1] "A_1"  "B_2"  "C_3"  "D_4"  "E_5"  "F_6"  "G_7"  "H_8"  "I_9"  "J_10" "K_11" "L_12" "M_13" "N_14" "O_15"
    ## [16] "P_16" "Q_17" "R_18" "S_19" "T_20" "U_21" "V_22" "W_23" "X_24" "Y_25" "Z_26"

``` r
# first group
str_group_extract(strings, "([\\w])_(\\d+)", 1)
```

    ##  [1] "A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N" "O" "P" "Q" "R" "S" "T" "U" "V" "W" "X" "Y" "Z"

``` r
# second group
str_group_extract(strings, "([\\w])_(\\d+)", 2)
```

    ##  [1] "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"  "10" "11" "12" "13" "14" "15" "16" "17" "18" "19" "20" "21"
    ## [22] "22" "23" "24" "25" "26"
