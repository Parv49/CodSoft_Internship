#include <bits/stdc++.h>
int main(){
  char a;
  double operand1, operand2;
  printf("Enter operator (+, -, *, /): ");
  scanf("%c", &a);
  printf("Enter two operands (numbers): ");
  scanf("%lf %lf", &operand1, &operand2);
  switch (a){
    case '+':
      printf("%f + %f = %f\n", operand1, operand2, operand1 + operand2);
      break;
    case '-':
      printf("%f - %f = %f\n", operand1, operand2, operand1 - operand2);
      break;
    case '*':
      printf("%f * %f = %f\n", operand1, operand2, operand1 * operand2);
      break;
    case '/':
      printf("%f / %f = %f\n", operand1, operand2, operand1 / operand2);
      break;
    default:
      printf("Invalid operator entered.\n");   
  }
  return 0;
}