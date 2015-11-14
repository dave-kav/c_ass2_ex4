
#include "pal.h"

//--------------------------------------------------
// struct palNode definition 
//--------------------------------------------------

struct palNode {
	int number;
	int pointer_index;
	char* solving_array;
	int solved;
	struct palNode* next;
};

//--------------------------------------------------
// load_palNode_list_from_file 
//--------------------------------------------------

struct palNode* load_palNode_list_from_file(char file_name[]) {
	int num_of_lines = 0;
	int* words_per_line = NULL;
	char* str = read_entire_file_and_store_it_in_a_string(file_name);
	char*** content = parse_file_content(str, &num_of_lines, &words_per_line);
	struct palNode *root = NULL, **pp = &root;
	struct palNode curr;
	struct palNode temp;
for (int i = 0; i < num_of_lines; i++) {
	content = content + i;
		if (root == NULL) {
			*pp = malloc(1,sizeof(**pp));
			curr = **pp;
			curr.number = atoi(**content);
			curr.pointer_index = atoi(*(*content + 1));
			curr.solving_array = (*(*content + 2));
			curr.next = NULL;
		}
		else {
			*(pp + i) = malloc(1, sizeof(**pp));
			temp = **(pp + i);
			temp.number = atoi(**content);
			temp.pointer_index = atoi(*(*content + 1));
			//if ((*(*content + 2))!= NULL)
				temp.solving_array = (*(*content + 2));
			temp.next = NULL;
			curr.next = &temp;
			curr = temp;
		}
	}
	printf("\nOperation completed\n");
	return root;
}

//--------------------------------------------------
// print_numbers_of_list 
//--------------------------------------------------

void print_numbers_of_list(struct palNode* head) {

}

//--------------------------------------------------
// find_palindrome_in_list 
//--------------------------------------------------

struct palNode* find_palindrome_in_list(struct palNode* head, int num) {

}

//--------------------------------------------------
// show_info_of_a_number 
//--------------------------------------------------

void show_info_of_a_number(struct palNode* head, int num) {

}

//--------------------------------------------------
// add_palNode_from_keyboard 
//--------------------------------------------------

struct palNode* add_palNode_from_keyboard(struct palNode* head, int num, int pos) {

}

//--------------------------------------------------
// solve_palindrome_of_node 
//--------------------------------------------------

char* solve_palindrome_of_node(struct palNode* current_node) {

}

//--------------------------------------------------
// solve_a_palindrome 
//--------------------------------------------------

struct palNode* solve_a_palindrome(struct palNode* head, int num) {

}

//--------------------------------------------------
// find_previous_node 
//--------------------------------------------------

struct palNode* find_previous_node(struct palNode* head, struct palNode* pointAtMe) {

}

//--------------------------------------------------
// remove_a_palindrome 
//--------------------------------------------------

struct palNode* remove_a_palindrome(struct palNode* head, int num) {

}

//--------------------------------------------------
// get_length_of_list 
//--------------------------------------------------

int get_length_of_list(struct palNode* head) {

}

//--------------------------------------------------
// sort_the_list 
//--------------------------------------------------

struct palNode* sort_the_list(struct palNode* head, int length) {

}

//--------------------------------------------------
// write_to_file 
//--------------------------------------------------

void write_to_file(char str[], struct palNode* head) {

}



