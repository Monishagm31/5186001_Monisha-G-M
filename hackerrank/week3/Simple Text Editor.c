#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000


typedef struct StackNode {
    int op_type;           
    char *data;            
    struct StackNode *next;
} StackNode;

char S[MAX_LEN + 1] = "";   
int len = 0;                
StackNode* top = NULL;
void push(int op_type, const char *data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->op_type = op_type;
    node->data = strdup(data);  
    node->next = top;
    top = node;
}
StackNode* pop() {
    if (!top) return NULL;
    StackNode* temp = top;
    top = top->next;
    return temp;
}
void append(const char *w) {
    push(1, w);  
    strcat(S, w);
    len = strlen(S);
}
void delete(int k) {
    int start = len - k;
    char* deleted = (char*)malloc(k + 1);
    strncpy(deleted, S + start, k);
    deleted[k] = '\0';
    push(2, deleted);
    S[start] = '\0';
    len = strlen(S);
    free(deleted);
}
void undo() {
    StackNode* op = pop();
    if (!op) return;

    if (op->op_type == 1) {
        // Undo append
        int k = strlen(op->data);
        S[len - k] = '\0';
        len -= k;
    } else if (op->op_type == 2) {
        // Undo delete
        strcat(S, op->data);
        len = strlen(S);
    }
    free(op->data);
    free(op);
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char w[MAX_LEN + 1];
            scanf(" %[^\n]", w);  
            append(w);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            delete(k);
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (type == 4) {
            undo();
        }
    }
    return 0;
}

 