#include "sha-256.h"

namespace
{
    char problem[64];
    int problem_len;

    int points;

    char code_path[500];
    char statement_path[500];

    FILE* code;
    FILE* statement;

    char full_code[5000];
    char full_statement[5000];

    int code_len,statement_len;

    char language[32];
    int language_len;

    char prev_hash[100];
    char code_hash[100];
    char statement_hash[100];
    uint8_t tmp_hash[32];

    char author[32], solver[32], miner[32];
    int author_len, solver_len, miner_len;

    char comment[130];
    int comment_len;

    char full[300];
    int full_len;
    char full_hash[100];

    bool valid_hash(char* hash)
    {
        for(int i=0;i<64;++i)
        {
            if((hash[i]>='0'&&hash[i]<='9')||(hash[i]>='a'&&hash[i]<='f')) continue;
            else return false;
        }

        if(hash[64]==0) return true;
        else return false;
    }

    void get_garbage()
    {
        char garbage[20];
        fgets(garbage,20,stdin);
    }

    int read_line(char* out, int n)
    {
        fgets(out,n,stdin);
        int len=strlen(out)-1;
        out[len]=0;
        return len;
    }

    void get_input()
    {
        printf("Name of problem: ");
        problem_len=read_line(problem,64);
        puts(problem);

        printf("Points: ");
        scanf("%d",&points);
        printf("%d points\n",points);

        printf("Path to code: ");
        get_garbage();
        read_line(code_path,500);
        code=fopen(code_path,"r");
        if(code) printf("File \"%s\" successfully opened!\n",code_path);
        else printf("Unable to open \"%s\"\n",code_path);

        printf("Language: ");
        language_len=read_line(language,32);

        printf("Path to problem statement: ");
        read_line(statement_path,500);
        statement=fopen(statement_path,"r");
        if(statement) printf("File \"%s\" successfully opened!\n",statement_path);
        else printf("Unable to open \"%s\"\n",statement_path);

        printf("Previous Block hash: ");
        read_line(prev_hash,100);
        if(valid_hash(prev_hash)) printf("Valid hash (starts with %c, ends with %c).\n",prev_hash[0],prev_hash[63]);
        else puts("INVALID HASH!");

        printf("Problem Author: ");
        author_len=read_line(author,32);
        puts(author);

        printf("Problem Solver: ");
        solver_len=read_line(solver,32);
        puts(solver);

        printf("Miner: ");
        miner_len=read_line(miner,32);
        puts(miner);

        printf("128 char max one-line comment: ");
        comment_len=read_line(comment,130);
        puts(comment);

        code_len=fread(full_code,1,5000,code);
        run_sha_256(full_code,code_len,tmp_hash);
        hash_to_string(code_hash,tmp_hash);

        statement_len=fread(full_statement,1,5000,statement);
        run_sha_256(full_statement,statement_len,tmp_hash);
        hash_to_string(statement_hash,tmp_hash);
    }

    void merge_input()
    {
        memcpy(full,problem,problem_len);
        full_len+=problem_len;

        full_len+=sprintf(full+full_len,"%02d",points);

        memcpy(full+full_len,prev_hash,64);
        full_len+=64;

        memcpy(full+full_len,code_hash,64);
        full_len+=64;

        memcpy(full+full_len,language,language_len);
        full_len+=language_len;

        memcpy(full+full_len,statement_hash,64);
        full_len+=64;

        memcpy(full+full_len,author,author_len);
        full_len+=author_len;

        memcpy(full+full_len,solver,solver_len);
        full_len+=solver_len;

        memcpy(full+full_len,miner,miner_len);
        full_len+=miner_len;

        memcpy(full+full_len,comment,comment_len);
        full_len+=comment_len;
    }

    void mine()
    {
        full_len+=10;
        uint8_t pp=points/10*16+points%10;
        for(char a='a';a<='z';++a)
        {
            for(char b='a';b<='z';++b)
            {
                for(char c='a';c<='z';++c)
                {
                    for(char d='a';d<='z';++d)
                    {
                        for(char e='a';e<='z';++e)
                        {
                            for(char f='a';f<='z';++f)
                            {
                                for(char g='a';g<='z';++g)
                                {
                                    for(char h='a';h<='z';++h)
                                    {
                                        for(char i='a';i<='z';++i)
                                        {
                                            for(char j='a';j<='z';++j)
                                            {
                                                full[full_len-1]=j;
                                                full[full_len-2]=i;
                                                full[full_len-3]=h;
                                                full[full_len-4]=g;
                                                full[full_len-5]=f;
                                                full[full_len-6]=e;
                                                full[full_len-7]=d;
                                                full[full_len-8]=c;
                                                full[full_len-9]=b;
                                                full[full_len-10]=a;

                                                run_sha_256(full,full_len,tmp_hash);
                                                if(tmp_hash[0]==0x3f&&tmp_hash[1]==0x3f&&tmp_hash[2]==pp) return;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    //get_input();
    //merge_input();
    strcpy(full,"helloworld013f3f000000000000000000000000000000000000000000000000000000000000bf1bf6455f4e5eeee931e48112a0d746c16dcc6e6121e126c6430cab87ffba7cC++64c4dcd57fffe82304dca7c270914f3cd201d090490911bcb3181c5786e8e8a2notfoundyaxollumyaxollummy first DMOJ problem!\0");
    full_len=strlen(full);
    points=1;
    mine();
    hash_to_string(full_hash,tmp_hash);
    puts(full_hash);
    puts(full+full_len-10);
    // ayvkmm
/*
    puts("\nRESULTS\n----------------");
    printf("Code hash: %s\n",code_hash);
    printf("Statement hash: %s\n",statement_hash);
*/
}
