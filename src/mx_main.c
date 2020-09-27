#include "../inc/race01.h"

int main(int argc, char *argv[]) {

    if (argc != 5) {
        write(2,"./part_of_the_matrix [operand1] [operation] [operand2] [result]\n", 65);
        exit(-1);
    }
    char *a_char = mx_strtrim(mx_strdup(argv[1]));
    char *b_char = mx_strtrim(mx_strdup(argv[3]));
	char *result_char = mx_strtrim(mx_strdup(argv[4]));
    char *op = mx_strtrim(mx_strdup(argv[2]));
	char *out_error = NULL;
    if (mx_strlen(op) != 1 || (op[0] != '?' && op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/')) {
        out_error = mx_strjoin("Invalid operation: ",op);
        write(2,out_error,mx_strlen(out_error));
        write(2,"\n",1);
        exit(-1);
    }
    else
        if (!mx_noormal_num(a_char) || !mx_noormal_num(b_char)) {
            if(!mx_noormal_num(a_char))
                out_error = mx_strjoin("Invalid operand: ",a_char);
            else
                out_error = mx_strjoin("Invalid operand: ",b_char);
        write(2,out_error,mx_strlen(out_error));
        write(2,"\n",1);
        exit(-1);
        }
        else
            if(!mx_noormal_num(result_char)) {
                out_error = mx_strjoin("Invalid result: ",result_char);
                write(2,out_error,mx_strlen(out_error));
                write(2,"\n",1);
                exit(-1);
            }
         
        t_values *a = mx_get_possible_values(a_char);
        t_values *b = mx_get_possible_values(b_char);
        t_values *c = mx_get_possible_values(result_char);


        mx_show_all_nodes(mx_get_results(a, b, c, op[0]));

        
}


