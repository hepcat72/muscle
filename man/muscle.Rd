\name{muscle}
\alias{muscle}

\title{
Multiple Sequence Alignment
}
\description{
MUSCLE performs multiple sequence alignments of nucleotide or amino acid sequences.
}
\usage{
muscle(stringset, quiet = FALSE, ...)
}

\arguments{
  \item{stringset}{
An object of class \code{\link{XStringSet}}: \code{\link{DNAStringSet}}, \code{\link{RNAStringSet}}, or \code{\link{AAStringSet}}.
}
  \item{quiet}{
Logical, whether to prevent printing of the progress of the algorithm to the screen. Defaults to FALSE.
}
  \item{\dots}{
Arguments (options and flags) for the MUSCLE algorithm (see Details).
}

}
\details{
Arguments for the MUSCLE algorithm are either options or flags. Options take a variety of values, but flags are always logicals (TRUE or FALSE).
All options and flags are explained in detail on the MUSCLE website: \url{http://www.drive5.com/muscle/muscle_userguide3.8.html}

}

\value{
Output is an object of class \code{\link{MultipleAlignment}}: \code{\link{DNAMultipleAlignment}}, \code{\link{RNAMultipleAlignment}}, or \code{\link{AAMultipleAlignment}}.
}

\references{
Edgar, R.C. (2004) MUSCLE: multiple sequence alignment with high accuracy and high throughput. \emph{Nucleic Acids Res} \bold{32}, 1792-1797.
}
\author{
Algorithm by Robert C. Edgar. Ported into R by Alex T. Kalinka \email{alex.t.kalinka@gmail.com}
}
\note{
For further details see the MUSCLE website:
\url{http://www.drive5.com/muscle/}
}


\seealso{
\code{\link{umax}}
}
\examples{

## Align sequences in an XStringSet object.
aln <- muscle(stringset = umax)

## Switch on the diags flag.
aln <- muscle(stringset = umax, diags = TRUE)

}

