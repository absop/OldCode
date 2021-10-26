using Formatting


function print210(v::AbstractVector, column::Int64=10)
    function printrow(R::UnitRange{Int64})
        width = ndigits(maximum(v[R]), base=2)
        digits2 = [bitstring(v[i])[end-width+1:end] for i in R]
        digits10 = [format(v[i], width=width) for i in R]
        println(join(digits10, "\t"))
        println(join(digits2, "\t"), "\n")
    end

    start, rangelen = 1, length(v)
    while (start + column) <= rangelen
        printrow(start:start+column-1)
        start += column
    end
    start <= rangelen && printrow(start:rangelen)
end


function print2(v::AbstractVector, column::Int64)
    width = ndigits(maximum(v), base=2)
    digits2 = [bitstring(v[i])[end-width+1:end] for i in 1:12]
    digits10 = [format(v[i], width=width) for i in 1:12]
    blanks = join(" " for i in 1:width)
    aligned = [blanks for i in 1:column-1]
    push!(aligned, format(column, width=width))
    println(join(aligned, "\t"))
    println(join(digits10, "\t"))
    println(join(digits2, "\t"), "\n")
end