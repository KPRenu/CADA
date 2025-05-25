#include <stdio.h>
#include <omp.h>
#define nunits 2
#define ninst 6
typedef struct
{
    char type; 
    int src1;  
    int src2;  
    int dest;  
} inst;

typedef struct
{
    char type;  
    int op1;    
    int op2;    
    int result; 
    int status; 
} funit;

inst instructions[ninst] = {
    {'A', 2, 3, 1}, 
    {'M', 4, 5, 2}, 
    {'A', 1, 2, 3}, 
    {'M', 3, 3, 4}, 
    {'A', 5, 4, 5}, 
    {'M', 2, 2, 6}  
};

funit units[nunits];

void execute_instruction(int id, inst inst)
{

    for (int i = 0; i < 100000000; ++i); 

    if (inst.type == 'A')
    {
        units[id].result = inst.src1 + inst.src2;
    }
    else if (inst.type == 'M')
    {
        units[id].result = inst.src1 * inst.src2;
    }

    units[id].status = 0;
}

int main()
{

    for (int i = 0; i < nunits; ++i)
    {
        units[i].status = 0; 
    }

#pragma omp parallel for num_threads(ninst)
    for (int i = 0; i < ninst; ++i)
    {
      
        int id = -1;
#pragma omp critical
        {
            for (int j = 0; j < nunits; ++j)
            {
                if (units[j].status == 0)
                {
                    id = j;
                    units[j].status = 1; 
                    break;
                }
            }
        }
        if (id != -1)
        {

            execute_instruction(id, instructions[i]);
            printf("Executed instruction %d: Result = %d\n", i + 1, units[id].result);
        }
        else
        {
            printf("No free functional unit available for instruction %d\n", i + 1);
        }
    }
    return 0;
}
