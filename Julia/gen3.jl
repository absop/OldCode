

function gen3(depth)
    list = [0, 3, 9]
    for i ∈ 1:depth
        cnt = length(list)
        println(cnt)
        for i ∈ 2:cnt
            for j ∈ 1:cnt
                new = list[i] << ndigits(list[j], base=2) + list[j]
                push!(list, new)
            end
        end
    end
    return list
end


t3 = gen3(3)
println(t3)