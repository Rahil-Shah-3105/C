/**
 * @file
 * @brief [Postfix evaluation algorithm](https://www.includehelp.com/c/evaluation-of-postfix-expressions-using-stack-with-c-program.aspx) implementation
 * @details
 * The input postfix expression is of type string upto 49 characters (including space delimiters).
 * Supported operations- '+', '-', '/', '*', '%'
 * @author [Kumar Yash](https://github.com/kumaryash18)
 */
 
#include <stdio.h>	/// for IO operations
#include <string.h>	/// for strlen()
#include <ctype.h>	/// for isdigit()
#include <stdlib.h>	/// for exit()
#include <stdint.h>	/// for int8_t
#include <assert.h>	/// for assert

/**
 * @brief array implementation of stack using structure
 */
struct Stack {
	int8_t stack[20];		///< array stack
	int top;		///< stores index of the top element
};
struct Stack st;		///< global declaration of stack st

/**
 * @brief Function to push on the stack
 * @param opd number to be pushed in the stack
 * @returns void
 */
void push(int8_t opd) {
	fprintf(stderr, ">>> Entering push(opd=%d)\n", opd);
	if(st.top == 19)	{		// overflow condition
		printf("Stack overflow...");
		exit(1);
	}
	st.top++;
	st.stack[st.top] = opd;
	fprintf(stderr, "<<< Exiting push(opd=%d)\n", opd);
}

/**
 * @brief Function to pop from the stack
 * @returns popped number
 */
int8_t pop() {
	fprintf(stderr, ">>> Entering pop()\n");
	int8_t item;				///< to store the popped value to be returned
	if(st.top == -1) {		// underflow condition
		printf("Stack underflow...");
		exit(1);
	}
	item = st.stack[st.top];
	fprintf(stderr, "pop(): item → %d\n", item);
	st.top--;
	fprintf(stderr, "<<< Exiting pop()\n");
	return item;
}

/**
 * @brief Function to evaluate postfix expression
 * @param post the input postfix expression
 * @returns evaluated answer
 */
int8_t evaluate(char post[]) {
	fprintf(stderr, ">>> Entering evaluate(post=%s)\n", post);
	int8_t it1;
	int8_t it2;
	int8_t temp;
	int8_t number;
    int i;
    for(i = 0; i < strlen(post); i++) {
		if(post[i] == ' ') {
			continue;			// ignore delimiter
		}
		else if(isdigit(post[i])) {
			number = 0;
			do {
				fprintf(stderr, "evaluate(post=%s): number → %d\n", post, number);
				number = number * 10 + (post[i]-'0');
				i++;
			} while(i < strlen(post) && isdigit(post[i]));
			push(number);
		}
		else {
			it2 = pop();
			it1 = pop();
			switch(post[i]) {
				fprintf(stderr, "evaluate(post=%s): it2 → %d\n", post, it2);
				fprintf(stderr, "evaluate(post=%s): it1 → %d\n", post, it1);
				case '+':
				temp = it1 + it2; break;
				case '-':
				temp = it1 - it2; break;
				case '*':
				temp = it1 * it2; break;
				case '/':
				temp = it1 / it2; break;
				case '%':
				temp = it1 % it2; break;
				default:
				printf("Invalid operator"); exit(1);
			}
			push(temp);
		}
	}
	return pop();
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	fprintf(stderr, ">>> Entering test()\n");
    /* check sample test case
	   input: "2 10 + 9 6 - /"
	   expected output: 4
	 */
	char temp1[50] = "2 10 + 9 6 - /";
	assert(evaluate(temp1) == 4); 			/// this ensures that the algorithm works as expected
	/* input: "4 2 + 3 5 1 - * +"
	   expected output: 18
	 */
	char temp2[50] = "4 2 + 3 5 1 - * +";
	assert(evaluate(temp2) == 18); 			/// this ensures that the algorithm works as expected
	printf("All tests have successfully passed!\n");
	fprintf(stderr, "<<< Exiting test()\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	fprintf(stderr, ">>> Entering main()\n");
	st.top = -1;			/// initialize
	test();				/// run self-test implementations
	fprintf(stderr, "main(): st.top → %d\n", st.top);
	fprintf(stderr, "<<< Exiting main()\n");
	return 0;
}
