#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define XPREVN		(64*1024*1024)				/* PI(XPREVN) : 3957809 */
#define XSQRTPREVN	(8*1024)
#define XPREVPI		(4*1024*1024)				/* PI(XPREVN) : 3957809 */
#define XMAXNTH		((LLong)10*1000*1000*1000)	/* NTH( 1E10 ) == 252097800623 */

int		*X_small_prime ,  X_pi_small_prime;
int		*X_pi_prev_N   , *X_prev_V;

#define XPREVDM		(7)
#define XPREVQ		(2*3*5*7*11*13*17)
#define XPREVPHQ	(1*2*4*6*10*12*16)

#ifdef _MSC_VER
#pragma warning( disable : 4244 )

typedef __int64		LLong;
#define LLFmt		"I64d"

#else

typedef long long	LLong;
#define LLFmt		"lld"

#endif


static LLong phiX_p( LLong x , LLong a )//
{

	if( a == XPREVDM )//#define XPREVDM		(7)
		return x / XPREVQ * XPREVPHQ + X_prev_V[ x % XPREVQ ];
		//#define XPREVQ		(2*3*5*7*11*13*17)==510510
		//#define XPREVPHQ	(1*2*4*6*10*12*16)==92160
		//int	*X_pi_prev_N   , *X_prev_V;

	if( x < X_small_prime[a-1] )//int	*X_small_prime ,  X_pi_small_prime;
		return 1;

	return phiX_p( x , a - 1 ) - phiX_p( x / X_small_prime[a-1] , a - 1 );//

}

LLong phiX( LLong X )
{
	LLong cubeRootX  , max , len3 , len2 , s , i , k;
	LLong sum , p;

	if( X <= XPREVN )
	return X_pi_prev_N[X];//int	*X_pi_prev_N   , *X_prev_V;

	max   = (LLong)(pow( (double)X , 2./3 ) + 2);

	cubeRootX = (LLong)(pow( (double)X , 1./3 ) + 0.5);//ËÄÉáÎåÈë

	if( cubeRootX*cubeRootX*cubeRootX > X )
		cubeRootX--;

	len3 = X_pi_prev_N[cubeRootX];//int	*X_pi_prev_N   , *X_prev_V;
	sum = 0; s = 0; k = max -1 ;
	for( i = len3; ;++i )
	{

		p = X_small_prime[i];

		if( p * p > X ) break;

		s += X_pi_prev_N[k] - X_pi_prev_N[(int)((double)X/p)];

		k = (int)((double)X/p);

		sum += s;

	}

	len2 = X_pi_prev_N[p-1];

	sum = (len2-len3)*X_pi_prev_N[max-1] - sum;

	sum = len3 * (len3-1)/2 - len2 * (len2-1) / 2 + sum;

	return phiX_p( X , len3 ) - sum + len3 - 1;

}

void initSmallPrime()//

{
	int i , j;
	char *mark = (char*)calloc(1,XPREVN/2+1);//#define XPREVN		(64*1024*1024)

	X_small_prime = (int*)calloc(sizeof(int),XPREVPI );//#define XPREVPI		(4*1024*1024)
	X_pi_prev_N   = (int*)calloc(sizeof(int),XPREVN+1);//#define XPREVN		(64*1024*1024)
	X_prev_V	  = (int*)calloc(sizeof(int),XPREVQ+1);//#define XPREVQ		(2*3*5*7*11*13*17)

	for( i = 3; i <= XSQRTPREVN; i += 2 )//#define XSQRTPREVN	(8*1024)
	{
		if( mark[i/2] ) continue;
		for( j = i*i/2; j <= XPREVN/2; j+=i )//#define XPREVN		(64*1024*1024)
			mark[j] = 1;
	}

	X_small_prime[0] = 2;
	X_pi_small_prime = 1;
	X_pi_prev_N[0] = X_pi_prev_N[1] = 0;
	X_pi_prev_N[2] = 1;

	for( i = 3; i <= XPREVN; i += 2 )//#define XPREVN		(64*1024*1024)
	{
		if( mark[i/2] )
			X_pi_prev_N[i+1] = X_pi_prev_N[i] = X_pi_prev_N[i-1];
		else
		{
			X_pi_prev_N[i+1] = X_pi_prev_N[i] = 1 + X_pi_prev_N[i-1];
			X_small_prime[X_pi_small_prime++] = i;
		}
	}
	free(mark);

	for( i = 0; i < XPREVQ; ++i )//#define XPREVQ		(2*3*5*7*11*13*17)
		X_prev_V[i] = i;

	for( i = 1; i <= XPREVDM; ++i )
		for( j = XPREVQ-1; j >= 0; --j )

			X_prev_V[j] -= X_prev_V[ j/X_small_prime[i-1] ];
}

int main()

{

    LLong	x , r;
    clock_t start,end;
	initSmallPrime();
	printf("Input a number:\t" );
	while( 1 == scanf( "%" LLFmt "", &x ) && x >= 0 && x <= (LLong)1 << 38 )
	{
		start=clock();
		r = phiX( x );
		end=clock();
		printf( "PI( %" LLFmt " ) == %" LLFmt "\tTime:%ldms\n\n\n" , x , r,end-start );
		printf("Input a number:\t" );
	}

return 0;

}