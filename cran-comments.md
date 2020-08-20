This is a resubmission. 


## Your comments

> Thanks,
> 
> Please add \value to all .Rd files for exported functions and explain
> the functions results in the documentation.
> f.i.: time_stamp.Rd
> If a function does not return a value, please document that too, e.g.
> \value{None}.
> 
> The \description tag in the .Rd files should be one or two sentences on
> how the function works and what it's good for. Don't just repeat the
> function name.
> F.i.: stats_modus_multi.Rd
> 
> An .Rd file title should:
> - be capitalized
> - not end in a period
> - be at most 65 characters long
> - exist and stand alone (there must be exactly one title)
> Please adjust to these standards and again don't simply repeat the name.
> https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Documenting-functions
> F.i.: stats_modus_multi.Rd
> 
> Please fix and resubmit, and document what was changed in the submission
> comments.



## My actions

- added titles according to suggestions
- added value entries according to suggestions



## Test environments

* Ubuntu 16.04 (on travis-ci), R old, release, devel
* Win-builder (devel and release)
* local Win10 R 3.6.3


## R CMD check results

0 errors | 0 warnings | 1 note

* This is a new release.
