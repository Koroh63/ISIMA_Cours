int main(void){
    int a = -3;
    int b = 4; 
    
}

int abs(int a)
{
    if(a < 0 ){
        a = a * -1;
    }
    return a;

}

int min(int a,int b){
    if (a > b)
        return b;
    else
        return a;
}

int max(int a,int b){
    if (a < b)
        return b;
    else
        return a;
}

void loop100(void){
    for(int i = 0; i<100;i++){

    }
}

void zeros(int* tab){
    for(int i=0;i<10;i++)
        tab[i] = 0;
}