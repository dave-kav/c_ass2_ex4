#pragma warning(disable:4996)
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
	int num_of_lines = 0, size = 0;
	int* words_per_line = NULL;
	char* str = read_entire_file_and_store_it_in_a_string(file_name);
	char*** content = parse_file_content(str, &num_of_lines, &words_per_line);
	struct palNode *curr = NULL, *head = NULL;
	struct palNode *ptr = NULL;

for (int i = 0; i < num_of_lines; i++) {
	*content = *(content + i);
		if (head == NULL) {
			ptr = (struct palNode*)malloc(sizeof(struct palNode));
			head = ptr;
			head->number = atoi(**content);
			head->pointer_index = atoi(*(*content + 1));
			if (*(*(*content + 2)) != '\n')
			{
				head->solving_array = (*(*content + 2));
				head->solved = 1;
			}
			else {
				head->solved = 0;
				head->solving_array = NULL;
			}
			head->next = NULL;
			curr = head;
		}
		else {
			ptr = ptr + 1;
			ptr = (struct palNode *)malloc(sizeof(struct palNode));
			ptr->number = atoi(**content);
			ptr->pointer_index = atoi(*(*content + 1));
			//printf("%s", ((*(*content + 1) + 0)));
			//printf("%s", ((*(*content + 1) + 8)));
			//printf("%s", ((*(*content + 1) + 0)));
			size = strlen(**content);
			printf((**(content)+size));
			if ((**(content) + size) == '\n') {
				ptr->solved = 0;
				ptr->solving_array = NULL;
			}
			//if (memchr((*(*content + 2)), 'a', 10) == NULL) {
			//	if (memchr((*(*content + 2)), 'd', 10) == NULL) {
			//		if (memchr((*(*content + 2)), 'w', 10) == NULL) {
			//			if (memchr((*(*content + 2)), 'x', 10) == NULL) {
			//				ptr->solved = 0;
			//				ptr->solving_array = NULL;
			//			}
			//		}
			//	}
			//}
			else {
				ptr->solving_array = (*(*content + 2));
				ptr->solved = 1;
			}
			
			ptr->next = NULL;
			curr->next = ptr;
			curr = ptr;
		}
	}
	printf("\nOperation completed\n");
	return head;
}

//--------------------------------------------------
// print_numbers_of_list 
//--------------------------------------------------

void print_numbers_of_list(struct palNode* head) {
	printf("\nThe length of the list is %d\n", find_size_of_list(head));
	struct palNode* current = head;
	int i = 0;

	while (current != NULL) {
		printf("Number %d = %d\n", i, current->number);
		current = current->next;
		i = i + 1;
	}
	printf("Operation Completed\n");
}

//--------------------------------------------------
// find_palindrome_in_list 
//--------------------------------------------------

struct palNode* find_palindrome_in_list(struct palNode* head, int num) {
	struct palNode* current = head;
	int i = 0;

	while (current != NULL) {
		if (current->number == num)
			return current;
		else
			current = current->next;
	}
	return NULL;
}

//--------------------------------------------------
// show_info_of_a_number 
//--------------------------------------------------

void show_info_of_a_number(struct palNode* head, int num) {
	struct palNode* current = find_palindrome_in_list(head, num);
	if (current == NULL)
		printf("Sorry, the number is not int the list\n");
	else {
		printf("Number: %d\n", current->number);
		printf("Pointer at index: %d\n", current->pointer_index);
		if (current->solved == 1)
			printf("Solved in %d movements: %s\n", strlen(current->solving_array), current->solving_array);
		else
			printf("Unsolved\n");
	}
	printf("Operation completed\n");
}

//--------------------------------------------------
// add_palNode_from_keyboard 
//--------------------------------------------------

struct palNode* add_palNode_from_keyboard(struct palNode* head, int num, int pos) {
	struct palNode* current = find_palindrome_in_list(head, num);
	struct palNode* temp = head;
	if (current != NULL) {
		printf("Sorry, the node was already in the list\n");
		return NULL;
	}
	current = (struct palNode *)malloc(sizeof(struct palNode));
	current->number = num;
	current->pointer_index = pos;
	current->solved = 0;
	current->solving_array = NULL;
	current->next = NULL;
	
	if (head != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = current;
	}
	else {
		head = (struct palNode *)malloc(sizeof(struct palNode));
		head = current;
	}
	printf("Operation completed\n");
	return head;
}

//--------------------------------------------------
// solve_palindrome_of_node 
//--------------------------------------------------

char* solve_palindrome_of_node(struct palNode* current_node) {
	int num = current_node->number;
	int temp = num;
	int size = 0;
	int index_pointer = current_node->pointer_index;
	while ((temp % 10) != 0)
	{
		size = size + 1; 
		temp = temp / 10;
	}
	int dummy1 = 0;
	int* a = malloc(size*sizeof(int));
	initialise_array(a, size, num);
	return get_solving_array(a, size, (a + index_pointer), &dummy1);
}

//--------------------------------------------------
// solve_a_palindrome 
//--------------------------------------------------

struct palNode* solve_a_palindrome(struct palNode* head, int num) {
	struct palNode* current = find_palindrome_in_list(head, num);
	if (current == NULL) {
		printf("Sorry, this number is not in the list");
		return NULL;
	}
	current->solving_array = solve_palindrome_of_node(current);
	current->solved = 1;
	printf("Operation completed\n");
	return head;
}

//--------------------------------------------------
// find_previous_node 
//--------------------------------------------------

struct palNode* find_previous_node(struct palNode* head, struct palNode* pointAtMe) {
	struct palNode* current = head;
	struct palNode* prev = head;
	int index = 0;
	while (current != pointAtMe) {
		prev = current;
		current = current->next;
	}
	return prev;
}

//--------------------------------------------------
// remove_a_palindrome 
//--------------------------------------------------

struct palNode* remove_a_palindrome(struct palNode* head, int num) {
	struct palNode* delete = find_palindrome_in_list(head, num);
	struct palNode* prev = find_previous_node(head, delete);
	//beginning of list
	if (delete == head)
		head = delete->next;
	//end of list
	int delete_index = 0;
	for (struct palNode* curr = head; curr->number != num; curr = curr->next) {
		delete_index = delete_index + 1;
	}
	if (delete_index == find_size_of_list(head))
		prev->next = NULL;
	//anywhere else in list
	else 
		prev->next = delete->next;
	free(delete->solving_array);
	free(delete);
	printf("Operation completed\n");
	return head;
}

//--------------------------------------------------
// find_size_of_list
//--------------------------------------------------

int find_size_of_list(struct palNode* head) {
	struct palNode* current = head;
	int size = 0;

	while (current != NULL) {
		size = size + 1;
		current = current->next;
	}
	return size;
}

//--------------------------------------------------
// swap 
//--------------------------------------------------

void swap(struct palNode* a, struct palNode* b) {
	struct palNode* temp = a;
	a = b;
	b = temp;
}

//--------------------------------------------------
// sort_the_list 
//--------------------------------------------------

struct palNode* sort_the_list(struct palNode* head, int length) {
	int swapped, i;
	struct palNode *ptr1 = head;
	struct palNode *ptr2 = NULL;

	/* Checking for empty list */
	if (ptr1 == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = head;

		while (ptr1->next != ptr2)
		{
			if (strlen(ptr1->solving_array) > strlen(ptr1->next->solving_array))
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1;
	} while (swapped);
	printf("Operation completed\n");
}

//--------------------------------------------------
// write_to_file 
//--------------------------------------------------

void write_to_file(char str[], struct palNode* head) {
	struct palNode* current = head;
	FILE *f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	while (current != NULL) {
		if (current->solved == 1)
			fprintf(f, "%d\t%d\t%s\n", current->number, current->pointer_index, current->solving_array);
		else
			fprintf(f, "%d\t%d\n", current->number, current->pointer_index);
		current = current->next;
	}
	printf("Operation Completed\n");
}



