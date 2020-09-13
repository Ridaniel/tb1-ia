#ifndef __PAR__HPP__
#define __PAR__HPP__
template<typename tipoDato1, typename tipoDato2>
struct Par
{
	tipoDato1 prime;
	tipoDato2 secun;
	Par(tipoDato1 a, tipoDato2 b) {
		prime = a;
		secun = b;
	}
	Par() {};
};
#endif // !__PAR__HPP__

