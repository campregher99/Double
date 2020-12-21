#ifndef DOUBLE_H
#define DOUBLE_H 
#ifndef MORE
#define MORE value
#endif
class Double
{
private:
	MORE int value=0;
	static int multiplier= 10;
	int lastMultiplier=multiplier;
	
public:
	Double()=default;
	template <typename T> Double(T _number) : value {_number*multiplier} {};
	static bool setMultiplier(int _multiplier);
	~Double()=default;

	double getValue() const;
	int getRowValue() const;
	template <typename T> bool setValue(const T& _number);

	template <typename T> T operator+(const T& _number) const;
	Double operator+(const Double& _double) const;
	template <typename T> T operator-(const T& _number) const;
	Double operator-(const Double& _double) const;
	template <typename T> T operator*(const T& _number) const;
	Double operator*(const Double& _double) const;
	template <typename T> T operator/(const T& _number) const;
	Double operator/(const Double& _double) const;

	template <typename T> Double operator=(const T& _number);
	Double operator=(const Double& _double);
	template <typename T> Double operator+=(const T& _number);
	Double operator+=(const Double& _double);
	template <typename T> Double operator-=(const T& _number);
	Double operator-=(const Double& _double);
	template <typename T> Double operator*=(const T& _number);
	Double operator*=(const Double& _double);
	template <typename T> Double operator/=(const T& _number);
	Double operator/=(const Double& _double);

	template <typename T> bool operator==(const T& _number) const;
	bool operator==(const Double& _double) const;
	template <typename T> bool operator!=(const T& _number) const;
	bool operator!=(const Double& _double) const;
	template <typename T> bool operator<(const T& _number) const;
	bool operator<(const Double& _double) const;
	template <typename T> bool operator>(const T& _number) const;
	bool operator>(const Double& _double) const;
	template <typename T> bool operator<=(const T& _number) const;
	bool operator<=(const Double& _double) const;
	template <typename T> bool operator>=(const T& _number) const;
	bool operator>=(const Double& _double) const;

	
protected: 
	static int getMultiplier();
	double adjustValue() const;
	void adjustValue();
};

template <typename T> bool setValue(const T& _number)
{
	if(lastMultiplier!=multiplier)
		adjustValue();
	value=_number*multiplier;
}

template <typename T> T operator+(const T& _number) const
{
	return getValue()+_number;
}

template <typename T> T operator-(const T& _number) const
{
	return getValue()-_number;
}

template <typename T> T operator*(const T& _number) const
{
	return getValue()*_number;
}

template <typename T> T operator/(const T& _number) const
{
	return getValue()/_number;
}

template <typename T> Double operator=(const T& _number)
{
	if(lastMultiplier!=multiplier)
		adjustValue();
	value=_number*multiplier;
	return *this;
}

template <typename T> Double operator+=(const T& _number)
{
	*this=*this+_number;
	return *this;
}

template <typename T> Double operator-=(const T& _number)
{
	*this=*this-_number;
	return *this;
}

template <typename T> Double operator*=(const T& _number)
{
	*this=*this*_number;
	return *this;
}

template <typename T> Double operator/=(const T& _number)
{
	*this=*this/_number;
	return *this;
}

template <typename T> bool operator==(const T& _number) const
{
	if(getValue()==_number)
		return true;
	return false;
}

template <typename T> bool operator!=(const T& _number) const
{
	if(!(*this==_number))
		return true;
	return false;
}


#endif