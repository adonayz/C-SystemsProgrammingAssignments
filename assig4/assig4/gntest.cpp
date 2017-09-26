#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/** Program to demonstrate the GeneralNumber class and its subclasses.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words.
 */
int main(int argc, char* argv[]) {

  GeneralNumber* g1 = new GeneralNumber();
  char* gs = g1->toString(); // Generate string version.
  printf("%s\n", gs); 
  // We don't need the string any more.
  free(gs);
  gs = g1->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralLong* g2 = new GeneralLong(2000L);
  gs = g2->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g2->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g3 = new GeneralLong(5000L);
  gs = g3->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g3->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g4 = new GeneralRational(4000L, 3000L);
  gs = g4->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g4->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  // Now for some conversions!

  GeneralNumber* g5 = g2->toGeneralRational();
  gs = g5->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g6 = g4->toGeneralLong();
  gs = g6->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);

  printf("\nStudent made conversions (Part 4)\n");

  char* example1;
  char* example2;
  
  GeneralRational* g22 = new GeneralRational(8L, 2L);
  GeneralLong* g23 = g22->toGeneralLong();
  example1 = g22->toString();
  gs = g23->toString(); // Generate string version.
  printf("Converting %s to %s\n",example1, gs); 
  free(gs);
  free(example1);

  GeneralRational* g26 = new GeneralRational(9L, 2L);
  GeneralLong* g27 = g26->toGeneralLong();
  example1 = g26->toString();
  gs = g27->toString(); // Generate string version.
  printf("Converting %s to %s\n",example1, gs); 
  free(gs);
  free(example1);

  GeneralLong* g24 = new GeneralLong(125L);
  GeneralRational* g25 = g24->toGeneralRational();
  example1 = g24->toString();
  gs = g25->toString(); // Generate string version.
  printf("Converting %s to %s\n",example1, gs); 
  free(gs);
  free(example1);

  printf("\nDemostrating the use of toCanonicalForm()\n\n");

  // toCanonicalForm() example 1
  GeneralRational* g7 = new GeneralRational(4000L, 3000L);
  gs = g7->toString(); // Generate string version.
  printf("\nBefore using toCanonicalForm():\n%s\n", gs); 
  free(gs);
  g7->toCanonicalForm();
  gs = g7->toString(); // Generate string version.
  printf("After using toCanonicalForm():\n%s\n", gs); 
  free(gs);

  // toCanonicalForm() example 2
  GeneralRational* g8 = new GeneralRational(4000L, -3000L);
  gs = g8->toString(); // Generate string version.
  printf("\nBefore using toCanonicalForm():\n%s\n", gs); 
  free(gs);
  g8->toCanonicalForm();
  gs = g8->toString(); // Generate string version.
  printf("After using toCanonicalForm():\n%s\n", gs); 
  free(gs);

  // toCanonicalForm() example 3
  GeneralRational* g9 = new GeneralRational(-4000L, -3000L);
  gs = g9->toString(); // Generate string version.
  printf("\nBefore using toCanonicalForm():\n%s\n", gs); 
  free(gs);
  g9->toCanonicalForm();
  gs = g9->toString(); // Generate string version.
  printf("After using toCanonicalForm():\n%s\n", gs); 
  free(gs);

  printf("\nDemostrating the use of the add() function\n ");

  //add() example1
  printf("\nAdd General Long onto a General Long\n");

  GeneralLong* g10 = new GeneralLong(2000L);
  GeneralLong* g11 = new GeneralLong(500L);
  GeneralNumber* g12 = g10->add(g11);
  
  example1 = g10->toString();
  example2 = g11->toString();
  gs = g12->toString(); // Generate string versions.
  
  printf("Sum of %s and %s is equal to = %s\n",example1, example2, gs);
  free(example1);
  free(example2);
  free(gs);

  //add() example2
  printf("\nAdd General Rational onto a General Long\n");

  GeneralLong* g13 = new GeneralLong(50L);
  GeneralRational* g14 = new GeneralRational(90L, 6L);
  GeneralNumber* g15 = g13->add(g14);

  
  example1 = g13->toString();
  example2 = g14->toString();
  gs = g15->toString(); // Generate string versions.
  
  printf("Sum of %s and %s is equal to = %s\n",example1, example2, gs);
  free(example1);
  free(example2);
  free(gs);

  //add() example3
  printf("\nAdd General Long onto a General Rational\n");

  GeneralRational* g16 = new GeneralRational(10L, 3L);
  GeneralLong* g17 = new GeneralLong(20L);
  GeneralNumber* g18 = g16->add(g17);

  
  example1 = g16->toString();
  example2 = g17->toString();
  gs = g18->toString(); // Generate string versions.
  
  printf("Sum of %s and %s is equal to = %s\n",example1, example2, gs);
  free(example1);
  free(example2);
  free(gs);

   //add() example4
  printf("\nAdd General Rational onto a General Rational\n");

  GeneralRational* g19 = new GeneralRational(50L, 3L);
  GeneralRational* g20 = new GeneralRational(30L, 7L);
  GeneralNumber* g21 = g19->add(g20);

  
  example1 = g19->toString();
  example2 = g20->toString();
  gs = g21->toString(); // Generate string versions.
  
  printf("Sum of %s and %s is equal to = %s\n",example1, example2, gs);
  free(example1);
  free(example2);
  free(gs);

  // We don't need the objects any more.
  delete(g1);
  delete(g2);
  delete(g3);
  delete(g4);
  delete(g5);
  delete(g6);
  delete(g7);
  delete(g8);
  delete(g9);
  delete(g10);
  delete(g11);
  delete(g12);
  delete(g13);
  delete(g14);
  delete(g15);
  delete(g16);
  delete(g17);
  delete(g18);
  delete(g19);
  delete(g20);
  delete(g21);
  delete(g22);
  delete(g23);
  delete(g24);
  delete(g25);
  delete(g26);
  delete(g27);

}
