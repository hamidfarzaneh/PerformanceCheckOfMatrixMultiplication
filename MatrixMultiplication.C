// matrix multiplication using simple C 
#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_TYPE_INT 0
#define ELEMENT_TYPE_FLOAT 1
#define ELEMENT_TYPE_DOUBLE 2

typedef struct Matrices {
    void ** elements;
    int col_count ; 
    int row_count ;
    int element_type ;

}Matrix;
void print_matrix(const Matrix input);
void runMatMul( int row_count_a,int col_count_a , int row_count_b ,int col_count_b , int type );
void mat_mul(const Matrix A , const Matrix B , const Matrix C );
int main (){
    runMatMul(1000,1000,1000,1000,0);

    return 0;


}

void runMatMul( int row_count_a,int col_count_a , int row_count_b ,int col_count_b , int type ){
    Matrix A = *((Matrix *) malloc (sizeof(Matrix)));
    Matrix B = *((Matrix *) malloc (sizeof(Matrix)));
    Matrix C = *((Matrix *) malloc (sizeof(Matrix)));
    
    A.element_type = ELEMENT_TYPE_INT ;
    A.row_count = row_count_a;
    A.col_count = col_count_a;

    B.element_type = ELEMENT_TYPE_INT ;
    B.row_count = row_count_b;
    B.col_count = col_count_b;

    C.element_type = ELEMENT_TYPE_INT ;
    C.row_count = A.row_count;
    C.col_count = B.col_count;

    void ** A_rows ;
    void ** B_rows ;
    void ** C_rows ;
    if(type==0){
        A_rows =(void **) malloc(sizeof(int*) * A.row_count);
        A.element_type = ELEMENT_TYPE_INT;
        B_rows =(void **) malloc(sizeof(int*) * B.row_count);
        B.element_type = ELEMENT_TYPE_INT;
        C_rows = (void **)malloc(sizeof(int*) * C.row_count);
        C.element_type = ELEMENT_TYPE_INT;
    } else if (type == 1){
        A_rows =(void **) malloc(sizeof(float*) * A.row_count);
        A.element_type = ELEMENT_TYPE_FLOAT;
        B_rows =(void **) malloc(sizeof(float*) * B.row_count);
        B.element_type = ELEMENT_TYPE_FLOAT;
        C_rows =(void **) malloc(sizeof(float*) * C.row_count);
        C.element_type = ELEMENT_TYPE_FLOAT;
    } else if (type == 2){
        A_rows =(void **) malloc(sizeof(double*) * A.row_count);
        A.element_type = ELEMENT_TYPE_DOUBLE;
        B_rows =(void **) malloc(sizeof(double*) * B.row_count);
        B.element_type = ELEMENT_TYPE_DOUBLE;
        C_rows =(void **) malloc(sizeof(double*) * C.row_count);
        C.element_type = ELEMENT_TYPE_DOUBLE;
    }
    for(int i = 0 ; i < A.row_count;i++){
        void * A_row ;
        void * B_row ; 
        void * C_row ;
        if(type == 0){
            A_row =  malloc (sizeof(int) * A.col_count);
            B_row =  malloc (sizeof(int) * B.col_count);
            C_row =  malloc (sizeof(int) * C.col_count);
            for(int j = 0 ; j < A.col_count ; j++){
                ((int *)A_row)[j] = 1;
            }
            for(int j = 0 ; j < B.col_count ; j++){
                ((int *)B_row)[j] = 1;
            }

            ((int **) A_rows)[i] = (int *) A_row;
            ((int **) B_rows)[i] = (int *) B_row;
            ((int **) C_rows)[i] = (int *) C_row;
        } else if(type == 1){
            A_row =  malloc (sizeof(float) * A.col_count);
            B_row =  malloc (sizeof(float) * B.col_count);
            C_row =  malloc (sizeof(float) * C.col_count);
            for(int j = 0 ; j < A.col_count ; j++){
                ((float*)A_row)[j] = 1;
            }
            for(int j = 0 ; j < B.col_count ; j++){
                ((float*)B_row)[j] = 1;
            }
            ((float**) A_rows)[i] = (float*) A_row;
            ((float**) B_rows)[i] = (float*) B_row;
            ((float**) C_rows)[i] = (float*) C_row;
 
        } else if(type == 2){
            A_row = (int *) malloc (sizeof(double) * A.col_count);
            B_row = (int *) malloc (sizeof(double) * B.col_count);
            C_row = (int *) malloc (sizeof(double) * C.col_count);
            for(int j = 0 ; j < A.col_count ; j++){
                ((double*)A_row)[j] = 1;
            }
            for(int j = 0 ; j < B.col_count ; j++){
                ((double*)B_row)[j] = 1;
            }
            ((double**) A_rows)[i] = (double*) A_row;
            ((double**) B_rows)[i] = (double*) B_row;
            ((double**) C_rows)[i] = (double*) C_row;

        } 
    

    }
    A.elements = A_rows;
    B.elements = B_rows;
    C.elements = C_rows;

    mat_mul(A,B,C);
}

void mat_mul(const Matrix A , const Matrix B , const Matrix C ){
    if(A.element_type == ELEMENT_TYPE_INT){
        int ** A_elements = (int **)A.elements;
        int ** B_elements = (int **)B.elements;
        int ** C_elements = (int **)C.elements;
        for(int i = 0 ; i< A.row_count ; i++){
            for(int j = 0 ; j<B.col_count;j++){
                int mulSum = 0 ;
                for(int z = 0 ; z < A.col_count ; z++){
                    mulSum += (A_elements[i][z] * B_elements[z][j]);
                }
                C_elements[i][j] = mulSum;
           }
        }
    
    }
    else if(A.element_type == ELEMENT_TYPE_FLOAT){
        float** A_elements = (float**)A.elements;
        float** B_elements = (float**)B.elements;
        float** C_elements = (float**)C.elements;
        for(int i = 0 ; i< A.row_count ; i++){
            for(int j = 0 ; j<B.col_count;j++){
                int mulSum = 0 ;
                for(int z = 0 ; z < A.col_count ; z++){
                    mulSum += (A_elements[i][z] * B_elements[z][j]);
                }
                C_elements[i][j] = mulSum;
           }
        }
    
    }
    else if(A.element_type == ELEMENT_TYPE_DOUBLE){
        double** A_elements = (double**)A.elements;
        double** B_elements = (double**)B.elements;
        double** C_elements = (double**)C.elements;
        for(int i = 0 ; i< A.row_count ; i++){
            for(int j = 0 ; j<B.col_count;j++){
                int mulSum = 0 ;
                for(int z = 0 ; z < A.col_count ; z++){
                    mulSum += (A_elements[i][z] * B_elements[z][j]);
                }
                C_elements[i][j] = mulSum;
           }
        }
    
    }
    
}
void print_matrix(const Matrix input){
    printf("\n");
    if(input.element_type == ELEMENT_TYPE_INT){
        int ** elements = (int **) input.elements;
        for (int i =0 ;i<input.row_count ; i++ ){
            for(int j = 0 ; j < input.col_count ;j++){
                printf("%3d ",elements[i][j]);
            }
            printf("\n");

        }
    }
    else if(input.element_type == ELEMENT_TYPE_FLOAT){
        float ** elements = (float **) input.elements;
        for (int i =0 ;i<input.row_count ; i++ ){
            for(int j = 0 ; j < input.col_count ; j++){
                printf("%3f",elements[i][j]);
            }
            printf("\n");
        }
    }
    else if(input.element_type == ELEMENT_TYPE_DOUBLE){
        double** elements = (double **) input.elements;
        for (int i =0 ;i<input.row_count ; i++ ){
            for(int j = 0 ; j < input.col_count ; j++){
                printf("%3f",elements[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
 
}