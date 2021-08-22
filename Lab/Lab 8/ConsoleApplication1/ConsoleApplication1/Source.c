#include <stdio.h>
#include <stdlib.h>

#define ZERO 0
#define ONE 1
#define textPath "C:\\Users\\rasou\\Desktop\\ICSP\\Lab\\Lab 8\\Part4_AllFiles\\input.txt"

typedef struct icsp_student icsp_std;

struct icsp_student {
	char* first_name;
	char* last_name;
	char* student_number;
	float mid_term_exam_score;
	float final_exam_score;
	float homework_score;
	icsp_std* next;
};

icsp_std* create_linked_list(){
	icsp_std* head = malloc(sizeof(icsp_std));
	head->next = NULL;
	return head;
}

int set_new_std_next_of_head(icsp_std* head_of_list, icsp_std* new_std) {
	if (new_std == NULL || head_of_list == NULL)
		return 0;
	new_std->next = head_of_list->next;
	head_of_list->next = new_std;
	return 1;
}

int add_to_i(icsp_std* head_of_list, icsp_std* new_std, int i) {
	if (head_of_list == NULL)
		return ZERO;
	icsp_std* current_std = head_of_list->next;
	if (current_std == NULL && i == ZERO) {
		head_of_list->next = new_std;
		new_std->next = NULL;
		return ONE;
	}
	else if (current_std == NULL && i != ZERO){
		return ZERO;
	}
	int counter = ZERO;
	while (1){
		if (counter == i) {
			new_std->next = current_std->next;
			current_std->next = new_std;
			return ONE;
		}
		counter++;
		if (current_std->next == NULL && counter == i) {
			current_std->next = new_std;
			new_std->next = NULL;
			return ONE;
		}
		if (current_std->next == NULL && counter < i) {
			return ZERO;
		}
		current_std = current_std->next;
	}
}

char* read_line_from_input_file(FILE* input) {
	int line_length = ZERO;
	char* line = (char*)malloc(sizeof(char));
	*(line) = '0';
	char temp_char[1] = { ' ' };
	while (1) {
		fread(temp_char, sizeof(char), ONE, input);
		line_length++;
		line = (char*)realloc(line, sizeof(char) * line_length);
		line[line_length - ONE] = NULL;
		switch (temp_char[ZERO]){
		case '\n':
			return line;
			break;
		case EOF:
			return line;
			break;
		default:
			line[line_length - ONE] = temp_char[ZERO];
			break;
		}
	}
}

icsp_std* read_students_credentials_from_file(char* file_name) {
	FILE* input;
	icsp_std* list_students = create_linked_list();
	if (input = fopen(file_name, "r")) {
		int num_of_lines = atoi(read_line_from_input_file(input));
		for (int i = 0; i < num_of_lines; i++) {
			icsp_std* std = (icsp_std*)malloc(sizeof(icsp_std));
			std->first_name = read_line_from_input_file(input);
			std->last_name = read_line_from_input_file(input);
			std->student_number = read_line_from_input_file(input);
			std->mid_term_exam_score = atof(read_line_from_input_file(input));
			std->final_exam_score = atof(read_line_from_input_file(input));
			std->homework_score = atof(read_line_from_input_file(input));
			
			set_new_std_next_of_head(list_students, std);
		}
		fclose(input);
		return list_students;
	}
	return NULL;
}

icsp_std* find_student(icsp_std* list, int student_id){
	icsp_std* current_std = list->next;
	while (current_std != NULL){
		if (atoi(current_std->student_number) == student_id){
			return current_std;
		}
		current_std = current_std->next;
	}
	printf("No Student Found!\n");
	return NULL;
}

int delete_student(icsp_std* list, int student_id){
	icsp_std* current_std = list->next;
	icsp_std* prev_std = list;
	while (current_std != NULL){
		if (atoi(current_std->student_number) == student_id){
			prev_std->next = current_std->next;
			free(current_std);
			return 1;
		}
		current_std = current_std->next;
		prev_std = prev_std->next;
	}
	return 0;
}

int print_reverse(icsp_std *head){
	if (head == NULL){
		return 0;
	}
	print_reverse(head->next);
	printf("%s\n", head->first_name);
	printf("%s\n", head->last_name);
	printf("%s\n", head->student_number);
	printf("%.2f\n", head->mid_term_exam_score);
	printf("%.2f\n", head->final_exam_score);
	printf("%.2f\n", head->homework_score);
	printf("====================\n");
	return 1;
}

int delete_all(icsp_std *head){
	if (head == NULL){
		return 0;
	}
	delete_all(head->next);
	free(head);
	return 1;
}


int main(){
	icsp_std* list = read_students_credentials_from_file(textPath);
	delete_all(list->next);
	return 0;
}