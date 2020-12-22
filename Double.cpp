#include "Double.h"

static bool Double::setMultiplier(int _multiplier)
{
	if(_multiplier<10)
		return false;
	multiplier=_multiplier;
	return true;
}

double Double::getValue() const
{
	if(lastMultiplier!=multiplier)
		return value/(double)lastMultiplier;
	return value/(double)multiplier;
}

int Double::getRowValue() const
{
	if(lastMultiplier!=multiplier)
	{
		int newValue=value*adjustValue();
		return newValue;
	}
	return value;
}

Double Double::operator+(const Double& _double) const
{
	Double* newDouble;
	newDouble->setValue(getRowValue()+_double.getRowValue());
	return *newDouble;
}

Double Double::operator-(const Double& _double) const
{
	Double* newDouble;
	newDouble->setValue(getRowValue()-_double.getRowValue());
	return *newDouble;
}

Double Double::operator*(const Double& _double) const
{
	Double* newDouble;
	newDouble->setValue(getRowValue()*_double.getValue());
	return *newDouble;
}

Double Double::operator/(const Double& _double) const
{
	Double* newDouble;
	newDouble->setValue(getRowValue()/(double)_double.getRowValue()*multiplier);
	return *newDouble;
}

Double Double::operator=(const Double& _double)
{
	if(multiplier!=lastMultiplier)
		adjustValue();
	value=_double.getRowValue();
	return *this;
}

Double Double::operator+=(const Double& _double)
{
	*this=*this+_double;
	return *this;
}

Double Double::operator-=(const Double& _double)
{
	*this=*this-_double;
	return *this;
}

Double Double::operator*=(const Double& _double)
{
	*this=*this*_double;
	return *this;
}

Double Double::operator/=(const Double& _double)
{
	*this = *this / _double;
	return *this;
}

bool Double::operator==(const Double& _double) const
{
	if(getRowValue()==_double.getRowValue())
		return true;
	return false;
}

bool Double::operator!=(const Double& _double) const
{
	if(!(*this==_double))
		return true;
	return false;
}

bool Double::operator<(const Double& _double) const
{
	if(getRowValue()<_double.getRowValue())
		return true;
	return false;
}

bool Double::operator>(const Double& _double) const
{
	if(getRowValue()>_double.getRowValue())
		return true;
	return false;
}

bool Double::operator<=(const Double& _double) const
{
	if(*this==_double||*this<_double)
		return true;
	return false;
}

bool operator>=(const Double& _double) const
{
	if(*this==_double||*this>_double)
		return true;
	return false;
}

static int getMultiplier()
{
	return multiplier;
}

double adjustValue() const
{
	return (double)multiplier/lastMultiplier;
}

void adjustValue()
{
	value*=(double)multiplier/lastMultiplier;
	lastMultiplier = multiplier;
}