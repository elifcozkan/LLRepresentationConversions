/*
Author		: Elif Ozkan
Create Date	: 15/10/2023
Description	: This project converts three different coordinate representations into each other.
Contact		: elifcozkan@gmail.com
*/

#pragma once

#include <stdlib.h>
#include <ctype.h> // for toUpper
#include <string.h> // for strcmp
#include <math.h>

#include <stdio.h>
#include <time.h>


void clear_input_buffer(void);

/* DMS2DD Function Definition */
void DMS2DD(const int* latDegDMS, const int* latMinDMS, const double* latSecDMS, const int* lonDegDMS,
	const int* lonMinDMS, const double* lonSecDMS, double* latDD, double* lonDD, char* latLetter, char* lonLetter);

/* DD2DDM Function Definition */
void DD2DDM(const double* latDD, const double* lonDD, int* latDegDDM, double* latDecMinDDM,
	int* lonDegDDM, double* lonDecMinDDM, char* latLetter, char* lonLetter);

/* DD2DMS Function Definition */
void DD2DMS(const double* latDD, const double* lonDD, int* latDegDMS, int* latMinDMS, double* latSecDMS,
	int* lonDegDMS, int* lonMinDMS, double* lonSecDMS, char* latLetter, char* lonLetter);

/* DMS2DDM Function Definition */
void DMS2DDM(const int* latDegDMS, const int* latMinDMS, const double* latSecDMS, const int* lonDegDMS, const int* lonMinDMS,
	const double* lonSecDMS, int* latDegDDM, double* latDecMinDDM, int* lonDegDDM, double* lonDecMinDDM, char* latLetter, char* lonLetter);

/* DDM2DMS Function Definition */
void DDM2DMS(const int* latDegDDM, const double* latDecMinDDM, const int* lonDegDDM, const double* lonDecMinDDM, int* latDegDMS, 
	int* latMinDMS, double* latSecDMS, int* lonDegDMS, int* lonMinDMS, double* lonSecDMS, char* latLetter, char* lonLetter, int letterFlag);

/* DDM2DD Function Definition */
void DDM2DD(const int* latDegDDM, const double* latDecMinDDM, const int* lonDegDDM, const double* lonDecMinDDM, double* latDD,
	double* lonDD, char* latLetter, char* lonLetter);
