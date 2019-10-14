// Function for Extended Euclidean algorithm
int eea (int r0, int r1, int *t, int *s)
{
	if (r1 == 0)
	{
		*s = 0;
		*t = 1;
		return r0;
	}

	int _s, _t;
	int gcd = eea (r1, r0 % r1, &_t, &_s);

	*s = _t - (r0/r1) * _s;
	*t = _s;

	return gcd;
}

int mod (int a, int m)
{
	int aux = a % m;
    
    if (aux < 0)
    	return m + aux;
    else
    	return aux;
}

int inverse (int r0, int r1)
{
	int t, s;

    eea (r0, r1, &s, &t);

    if (t < 0)
    	return t + r0;
    else
    	return t;
}