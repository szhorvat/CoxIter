/*
Copyright (C) 2013, 2014
Rafael Guglielmetti, rafael.guglielmetti@unifr.ch
*/

/*
This file is part of CoxIter.

CoxIter is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

CoxIter is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CoxIter. If not, see <http://www.gnu.org/licenses/>.
*/

/*!
 * \file number_rational.h
 * \brief Nombres rationnels (un int en haut, un int en bas). Surcharge des opérateurs classiques.
 * \author Rafael Guglielmetti
 * \class Number_rational number_rational.h
*/

#ifndef __NUMBER_RATIONAL_H__
#define __NUMBER_RATIONAL_H__

#include <iostream>
#include <string>

using namespace std;

#include "number_template.h"
#include "../string.h"
#include "../regexp.h"

#include <gmpxx.h>

class MPZ_rational : public Number_template
{
	public:
		mpz_class a;
		mpz_class b;

	private:
		/*! \fn update
		 * 	\brief Met à jour les attributs (gcd, isInt, ...)
		 */
		void update( );

	public:
		MPZ_rational( );
		
		MPZ_rational( mpz_class a, mpz_class b );
		MPZ_rational( mpz_class a );
		
		MPZ_rational( const int& i );
		MPZ_rational( string szRational );

		bool isInteger( ) const;
		bool isCOInteger( ) const;

		bool operator>=( int const& ) const;
		bool operator==( int const& ) const;
		bool operator==( MPZ_rational const& ) const;
		bool operator==( mpz_class const& ) const;
		bool operator!=( MPZ_rational const& ) const;
		
		MPZ_rational& operator=( long int );
		
		MPZ_rational operator+( MPZ_rational const &n ) const;
		MPZ_rational& operator+=( MPZ_rational const &n );

		MPZ_rational operator-( MPZ_rational const &n ) const;
		void opp( MPZ_rational* &_c ) const;
		MPZ_rational& operator-=( MPZ_rational const &n );
		
		MPZ_rational operator*( MPZ_rational const &n ) const;
		MPZ_rational& operator*=( MPZ_rational const &n );

		MPZ_rational operator/( MPZ_rational const &n ) const;
		MPZ_rational& operator/=( MPZ_rational const &n );

		void print( ostream & ) const;	
		
		string to_string( ) const;
};

ostream& operator<<( ostream& , MPZ_rational const & );
//BigInteger gcd( const BigInteger &, const BigInteger & );

#endif
