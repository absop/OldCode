
function primesCount(maxn::Int64)
	isprimes = trues(maxn)
	@inbounds for i = 3:2:isqrt(maxn)
		if isprimes[i]
			@inbounds for j = i^2:2i:maxn
				isprimes[j] = false
			end
		end
	end
	cnt = 1 # count for prime 2
	@inbounds for i = 3:2:maxn
		if isprimes[i]
			cnt += 1
		end
	end
	return cnt
end


function primes(maxn::Int64)
	half = cld(maxn, 2)
	isprimes = trues(half)
	for i = 3:2:isqrt(maxn)
		if isprimes[div(i + 1, 2)]
			for j = div(i^2 + 1, 2):i:half
				isprimes[j] = false
			end
		end
	end
	count(isprimes)
end


##################################################

using BenchmarkTools
using Combinatorics


# @btime primesCount(10^8)
# println(primesCount(10^8))
println(primes(10^8))
println(primesCount(10^8))

@btime primes(10^8)
@btime primesCount(10^8)
