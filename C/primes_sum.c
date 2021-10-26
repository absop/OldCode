#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

typedef long long LLong;

inline LLong V2IDX(LLong v, LLong N, LLong Ndr, LLong nv)
{
    return v >= Ndr ? (N / v - 1) : (nv - v);
}

LLong PrimeSum(LLong N)
{
    LLong *S;
    LLong *V;

    LLong r = (LLong)sqrt(N);
    LLong Ndr = N / r;

    assert(r * r <= N && (r + 1) * (r + 1) > N);

    LLong nv = r + Ndr - 1;

    V = (LLong *)malloc(sizeof(LLong) * nv);
    S = (LLong *)malloc(sizeof(LLong) * nv);

    for (LLong i = 0; i < r; i++)
        V[i] = N / (i + 1);
    for (LLong i = r; i < nv; i++)
        V[i] = V[i - 1] - 1;

    for (LLong i = 0; i < nv; i++)
        S[i] = V[i] * (V[i] + 1) / 2 - 1;

    for (LLong p = 2; p <= r; p++) {
        if (S[nv - p] > S[nv - p + 1]) {
            LLong sp = S[nv - p + 1];
            LLong p2 = p * p;
            for (LLong i = 0; i < nv; i++) {
                if (V[i] >= p2)
                    S[i] -= p * (S[V2IDX(V[i] / p, N, Ndr, nv)] - sp); else
                    break;
            }
        }
    }
    Ndr = S[0];
    free(S);
    free(V);
    return Ndr;
}

int main()
{
    clock_t st, et;
    LLong N = 10000000000;
    st = clock();
    printf("%lld\n", PrimeSum(N));
    et = clock();
    printf("Elapsed Time:%ldms\n", et - st);
}
