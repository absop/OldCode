
function flp2(n::Int64)
    for i in (1, 2, 4, 8, 16, 32)
        n |= n >> i
    end
    n - (n >> 1)
end

function clp2(n::Int64)
    for i in (1, 2, 4, 8, 16, 32)
        n |= n >> i
    end
    n + 1
end


function loopflp2(x::Int64)
    while true
        y = x
        x &= (x - 1)
        x == 0 && return y
    end
end

function testflp2(n::Int64)
    (function (x::Int64)
        cnt = 0
        while true
            cnt += 1
            y = x
            x &= (x - 1)
            x == 0 && return (y, cnt)
        end
    end)(n)
end


using BenchmarkTools


# @btime for i in 1:10^9
#     flp2(i)
# end
# @btime for i in 1:10^9
#     clp2(i)
# end

# @btime for i in 1:10^8
#     loopflp2(i)
# end

const n = 2^60-1
println(n)
println(clp2(n))
println(flp2(n))
println(loopflp2(n))
println(testflp2(n))

@btime flp2(n)
@btime loopflp2(n)
@btime testflp2(n)