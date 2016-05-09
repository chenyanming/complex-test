#ifndef __COMPLEX__
#define __COMPLEX__

class complex;
complex&
__doapl(complex* ths, const complex& r);

class complex
{
private://Data is in private
	double re, im;
public://Functions are in public
	//Constructor with default value and initialization list
	complex(double r = 0, double i = 0) : re(r), im(i) {}
	//Function Definition inside the class
	double real() const { return re; }
	double imag() const { return im; }
	//operator overloading
	complex& operator += (const complex&);

	friend complex& __doapl(complex *, const complex&);
};

//Function Definition outside the class
inline double
real(const complex& x)
{
	return x.real();
}

inline double
imag(const complex& x)
{
	return x.imag();
}
// Friend function - Do assignment plus definition
inline complex&
__doapl(complex* ths, const complex& r)
{
	// Friends access the private data.
	ths->re += r.re;
	ths->im += r.im;
	return *ths;

}

//membership function += overloading definition
inline complex&
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

//non membership function + overloading definition 
inline complex
operator + (const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

//non membership function
inline complex
conj(const complex& x)
{
	return complex(real(x), -imag(x));
}

#endif
