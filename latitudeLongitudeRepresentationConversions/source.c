/*
Author		: Elif Ozkan
Create Date	: 15/10/2023
Description	: This project converts three different coordinate representations into each other.
Contact		: elifcozkan@gmail.com (If you have suggestions please contact!)
*/

#define _CRT_SECURE_NO_WARNINGS

#include "source.h"

#define LETTERSIZE 2

char coordinateLetter[LETTERSIZE] = { 0 };
int letterFlag = 0;

int main(void) {

	/* DMS variables */
	int latDegDMS = 0;
	int latMinDMS = 0;
	double latSecDMS = 0;
	int lonDegDMS = 0;
	int lonMinDMS = 0;
	double lonSecDMS = 0;

	/* DD variables */
	double latDD = 0;
	double lonDD = 0;

	/* DDM variables */
	int latDegDDM = 0;
	int lonDegDDM = 0;
	double latDecMinDDM = 0;
	double lonDecMinDDM = 0;

	char latLetter[2] = { 'N','\0' };
	char lonLetter[2] = { 'E','\0' };

	int convertionType = 0;

	printf("Threre are several representations of Latitude and Longitudes.\n"			\
		"Some of them can be converted using this code.\n"								\
		"Decimal Degrees: Decimal fractions of a degree. Ex:  39.896244,   32.862393\n" \
		"Degree / Minutes / Seconds. Ex:  39%c53'46.48\"N, 32%c51'44.61\"E\n"			\
		"Degrees Decimal Minutes. Ex: 39%c53.775'N  32%c 51.744'E\n"					\
		"If you don't write letters default North and East will be used. \n", 248, 248, 248, 248);

	printf("Choose conversion using numbers below.\n"	\
			"Convertion from DMS to DD  -> 1\n"			\
			"Convertion from DD  to DDM -> 2\n"			\
			"Convertion from DD  to DMS -> 3\n"			\
			"Convertion from DMS to DDM -> 4\n"			\
			"Convertion from DDM to DMS -> 5\n"			\
			"Convertion from DDM to DD  -> 6\n");

tryAgain:
	printf("Type your choice:  ");
	int ret = scanf("%d", &convertionType);
	
	if (!ret) {
		printf("You wrote a word! Please try again...\n");
		return EXIT_FAILURE;
	}

	/* Letter Decision */
	printf("Do coordinates have letter? (Y/N)");
	(void)scanf("%s", &coordinateLetter);
	_strupr(coordinateLetter);

	if (coordinateLetter[0] == 'Y') {
		letterFlag = 1;
	}
	else if(coordinateLetter[0] == 'N')
		letterFlag = 0;
	else {
		printf("You should write Y or N only! \n");
		return EXIT_FAILURE;
	}

	clear_input_buffer();

	switch (convertionType)
	{
	case 1: printf("You choose DMS to DD conversion.\n" \
		"Please write latitude degree: ");
		(void)scanf("%d", &latDegDMS);
		printf("Please write latitude minutes: ");
		(void)scanf("%d", &latMinDMS);
		printf("Please write latitude seconds: ");
		(void)scanf("%lf", &latSecDMS);

		if (letterFlag) {
			printf("Please write latitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &latLetter);
			_strupr(latLetter);
			printf("%d%c %d\' %.3lf\'\' %c\n", latDegDMS, 248, latMinDMS, latSecDMS, latLetter[0]);
		}
		else {
			printf("%d%c %d\' %.3lf\'\'\n", latDegDMS, 248, latMinDMS, latSecDMS);
		}

		printf("Please write longitude degree: ");
		(void)scanf("%d", &lonDegDMS);
		printf("Please write longitude minutes: ");
		(void)scanf("%d", &lonMinDMS);
		printf("Please write longitude seconds: ");
		(void)scanf("%lf", &lonSecDMS);


		if (letterFlag) {
			printf("Please write longitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &lonLetter);
			_strupr(lonLetter);
			printf("%d%c %d\' %.3lf\'\' %c\n", lonDegDMS, 248, lonMinDMS, lonSecDMS, lonLetter[0]);
		}
		else {
			printf("%d%c %d\' %.3lf\'\'\n", lonDegDMS, 248, lonMinDMS, lonSecDMS);
		}

		/* Conversion function call */
		DMS2DD(&latDegDMS, &latMinDMS, &latSecDMS, &lonDegDMS, &lonMinDMS, &lonSecDMS, &latDD, &lonDD, &latLetter[0], &lonLetter[0]);

		/* Result print */
		printf("DD Latitude is %lf and DD Longitude is %lf \n", latDD, lonDD);

		break;

	case 2: printf("You choose DD to DDM conversion.\n" \
		"Please write latitude decimal degree: ");
		(void)scanf("%lf", &latDD);
		printf("Please write longitude decimal degree: ");
		(void)scanf("%lf", &lonDD);
		printf("Latitude: %lf Longitude: %lf\n", latDD, lonDD);

		/* Conversion function call */
		DD2DDM(&latDD, &lonDD, &latDegDDM, &latDecMinDDM, &lonDegDDM, &lonDecMinDDM, &latLetter[0], &lonLetter[0]);

		/* Result print */
		printf("DDM Latituse is %d%c %lf%c and DDM Longitude is %d%c %lf%c", latDegDDM, 248, latDecMinDDM, latLetter[0],
			lonDegDDM, 248, lonDecMinDDM, lonLetter[0]);

		break;

	case 3: printf("You choose DD to DMS conversion.\n" \
		"Please write latitude decimal degree: ");
		(void)scanf("%lf", &latDD);
		printf("Please write longitude decimal degree: ");
		(void)scanf("%lf", &lonDD);
		printf("Latitude: %lf Longitude: %lf\n", latDD, lonDD);

		/* Conversion function call */
		DD2DMS(&latDD, &lonDD, &latDegDMS, &latMinDMS, &latSecDMS, &lonDegDMS, &lonMinDMS, &lonSecDMS, &latLetter[0], &lonLetter[0]);

		/* Result print */
		printf("DMS Latituse is %d%c %d\' %lf%c and DMS Longitude is %d%c %d\' %lf%c", latDegDMS, 248, latMinDMS, latSecDMS,
			latLetter[0], lonDegDMS, 248, lonMinDMS, lonSecDMS, lonLetter[0]);

		break;

	case 4: printf("You choose DMS to DDM conversion.\n" \
		"Please write latitude degree: ");
		(void)scanf("%d", &latDegDMS);
		printf("Please write latitude minutes: ");
		(void)scanf("%d", &latMinDMS);
		printf("Please write latitude seconds: ");
		(void)scanf("%lf", &latSecDMS);

		if (letterFlag) {
			printf("Please write latitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &latLetter);
			_strupr(latLetter);
			printf("%d%c %d\' %.3lf\'\' %c\n", latDegDMS, 248, latMinDMS, latSecDMS, latLetter[0]);
		}
		else {
			printf("%d%c %d\' %.3lf\'\'\n", latDegDMS, 248, latMinDMS, latSecDMS);
		}


		printf("Please write longitude degree: ");
		(void)scanf("%d", &lonDegDMS);
		printf("Please write longitude minutes: ");
		(void)scanf("%d", &lonMinDMS);
		printf("Please write longitude seconds: ");
		(void)scanf("%lf", &lonSecDMS);

		if (letterFlag) {
			printf("Please write longitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &lonLetter);
			_strupr(lonLetter);
			printf("%d%c %d\' %.3lf\'\' %c\n", lonDegDMS, 248, lonMinDMS, lonSecDMS, lonLetter[0]);
		}
		else {
			printf("%d%c %d\' %.3lf\'\'\n", lonDegDMS, 248, lonMinDMS, lonSecDMS);
		}

		/* Conversion function call */
		DMS2DDM(&latDegDMS, &latMinDMS, &latSecDMS, &lonDegDMS, &lonMinDMS, &lonSecDMS, &latDegDDM, &latDecMinDDM, &lonDegDDM, &lonDecMinDDM, &latLetter[0], &lonLetter[0]);

		/* Result print */
		printf("DDM Latituse is %d%c %lf %c and DDM Longitude is %d%c %lf %c \n", latDegDDM, 248, latDecMinDDM, latLetter[0], lonDegDDM, 248, lonDecMinDDM, lonLetter[0]);

		break;

	case 5: printf("You choose DDM to DMS conversion.\n" \
		"Please write latitude degree: ");
		(void)scanf("%d", &latDegDDM);
		printf("Please write latitude decimal minutes: ");
		(void)scanf("%lf", &latDecMinDDM);

		if (letterFlag) {
			printf("Please write latitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &latLetter);
			_strupr(latLetter);
			printf("%d%c %.3lf %c\n", latDegDDM, 248, latDecMinDDM, latLetter[0]);
		}
		else {
			printf("%d%c %.3lf\n", latDegDDM, 248, latDecMinDDM);
		}

		printf("Please write longitude degree: ");
		(void)scanf("%d", &lonDegDDM);
		printf("Please write longitude decimal minutes: ");
		(void)scanf("%lf", &lonDecMinDDM);


		if (letterFlag) {
			printf("Please write longitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &lonLetter);
			_strupr(lonLetter);
			printf("%d%c %.3lf %c\n", lonDegDDM, 248, lonDecMinDDM, lonLetter[0]);
		}
		else {
			printf("%d%c %.3lf\n", lonDegDDM, 248, lonDecMinDDM);
		}

		DDM2DMS(&latDegDDM, &latDecMinDDM, &lonDegDDM, &lonDecMinDDM, &latDegDMS, &latMinDMS, &latSecDMS, 
			&lonDegDMS, &lonMinDMS, &lonSecDMS, &latLetter[0], &lonLetter[0], letterFlag);

		printf("DMS Latituse is %d%c %d\' %lf %c and DMS Longitude is %d%c %d\' %lf %c", latDegDMS, 248, latMinDMS, latSecDMS, latLetter[0],
			lonDegDMS, 248, lonMinDMS, lonSecDMS, lonLetter[0]);
		break;

	case 6: printf("You choose DDM to DD conversion.\n" \
		"Please write latitude degree: ");
		(void)scanf("%d", &latDegDDM);
		printf("Please write latitude decimal minutes: ");
		(void)scanf("%lf", &latDecMinDDM);

		if (letterFlag) {
			printf("Please write latitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &latLetter);
			_strupr(latLetter);
			printf("%d%c %lf\' %c \n", latDegDDM, 248, latDecMinDDM, latLetter[0]);
		}
		else {
			printf("%d%c %lf\' \n", latDegDDM, 248, latDecMinDDM);
		}

		printf("Please write longitude degree: ");
		(void)scanf("%d", &lonDegDDM);
		printf("Please write longitude decimal minutes: ");
		(void)scanf("%lf", &lonDecMinDDM);
		

		if (letterFlag) {
			printf("Please write longitude letter: ");
			clear_input_buffer();
			(void)scanf("%s", &lonLetter);
			_strupr(lonLetter);
			printf("%d%c %lf\' %c \n", lonDegDDM, 248, lonDecMinDDM, lonLetter[0]);
		}
		else {
			printf("%d%c %lf\' \n", lonDegDDM, 248, lonDecMinDDM);
		}

		DDM2DD(&latDegDDM, &latDecMinDDM, &lonDegDDM, &lonDecMinDDM, &latDD, &lonDD, &latLetter[0], &lonLetter[0]);
		printf("DD Latitude is %lf %c and DD Longitude is %lf %c\n", latDD, latLetter[0], lonDD, lonLetter[0]);
		break;

	default:
		printf("There is no such a case!\n");
		printf("Choose conversion using numbers below.\n"	\
			"Convertion from DMS to DD  -> 1\n"				\
			"Convertion from DD  to DDM -> 2\n"				\
			"Convertion from DD  to DMS -> 3\n"				\
			"Convertion from DMS to DDM -> 4\n"				\
			"Convertion from DDM to DMS -> 5\n"				\
			"Convertion from DDM to DD  -> 6\n");
		goto tryAgain;
	}

}

void clear_input_buffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}


void DMS2DD(const int* latDegDMS, const int* latMinDMS, const double* latSecDMS, const int* lonDegDMS,
	const int* lonMinDMS, const double* lonSecDMS, double* latDD, double* lonDD, char* latLetter, char* lonLetter)
{
	*latDD =  *latDegDMS + ((double)*latMinDMS / 60.0) + (*latSecDMS / 3600);
	*lonDD = *lonDegDMS + ((double)*lonMinDMS / 60.0) + (*lonSecDMS / 3600);
	
	if (*latLetter == 'S') {
		*latDD = -1 * (*latDD);
	}

	if (*lonLetter == 'W') {
		*lonDD = -1 * (*lonDD);
	}
}


void DD2DDM(const double* latDD, const double* lonDD, int* latDegDMS, double* latDecMinDDM,
	int* lonDegDMS, double* lonDecMinDDM, char* latLetter, char* lonLetter) {

	*latDegDMS = abs((int)*latDD);
	*lonDegDMS = abs((int)*lonDD);
	*latDecMinDDM = ( fabs(*latDD) - abs((int)*latDD)) * 60.0;
	*lonDecMinDDM = (fabs(*lonDD) - abs((int)*lonDD)) * 60.0;

	if (*latDD > 0) {
		*latLetter = 'N';
	}
	else {
		*latLetter = 'S';
	}

	if (*lonDD > 0) {
		*lonLetter = 'E';
	}
	else {
		*lonLetter = 'W';
	}
}

void DD2DMS(const double* latDD, const double* lonDD, int* latDegDMS, int* latMinDMS, double* latSecDMS,
	int* lonDegDMS, int* lonMinDMS, double* lonSecDMS, char* latLetter, char* lonLetter){

	*latDegDMS = abs((int)*latDD);
	*lonDegDMS = abs((int)*lonDD);
	double latMinD = (fabs(*latDD) - abs((int)*latDD)) * 60.0;
	double lonMinD = (fabs(*lonDD) - abs((int)*lonDD)) * 60.0;

	*latSecDMS = (fabs(latMinD) - abs((int)latMinD)) * 60.0;
	*lonSecDMS = (fabs(lonMinD) - abs((int)lonMinD)) * 60.0;
	*latMinDMS = (int)latMinD;
	*lonMinDMS = (int)lonMinD;

	if (*latDD > 0) {
		*latLetter = 'N';
	}
	else {
		*latLetter = 'S';
	}

	if (*lonDD > 0) {
		*lonLetter = 'E';
	}
	else {
		*lonLetter = 'W';
	}
}


void DMS2DDM(const int* latDegDMS, const int* latMinDMS, const double* latSecDMS, const int* lonDegDMS, const int* lonMinDMS,
	const double* lonSecDMS, int* latDegDDM, double* latDecMinDDM, int* lonDegDDM, double* lonDecMinDDM, char* latLetter, char* lonLetter) {

	*latDegDDM = *latDegDMS;
	*lonDegDDM = *lonDegDMS;

	*latDecMinDDM = *latMinDMS + (*latSecDMS / 60.0);
	*lonDecMinDDM = *lonMinDMS + (*lonSecDMS / 60.0);

}

void DDM2DMS(const int* latDegDDM, const double* latDecMinDDM, const int* lonDegDDM, const double* lonDecMinDDM, int* latDegDMS, int* latMinDMS, 
	double* latSecDMS, int* lonDegDMS, int* lonMinDMS, double* lonSecDMS, char* latLetter, char* lonLetter, int letterFlag) {

	*latDegDMS = *latDegDDM;
	*lonDegDMS = *lonDegDDM;

	double latSecD = (fabs(*latDecMinDDM) - abs((int)*latDecMinDDM)) * 60.0;
	double lonSecD = (fabs(*lonDecMinDDM) - abs((int)*lonDecMinDDM)) * 60.0;
	
	*latMinDMS = (int)*latDecMinDDM;
	*lonMinDMS = (int)*lonDecMinDDM;

	*latSecDMS = latSecD;
	*lonSecDMS = lonSecD;
}

void DDM2DD(const int* latDegDDM, const double* latDecMinDDM, const int* lonDegDDM, const double* lonDecMinDDM, double* latDD, double* lonDD, char* latLetter, char* lonLetter) {
	*latDD = (double)*latDegDDM + (*latDecMinDDM / 60.0);
	*lonDD = (double)*lonDegDDM + (*lonDecMinDDM / 60.0);
	
	if (*latLetter == 'S') {
		*latDD = -1 * (*latDD);
	}

	if (*lonLetter == 'W') {
		*lonDD = -1 * (*lonDD);
	}
}
