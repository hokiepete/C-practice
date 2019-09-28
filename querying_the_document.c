#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char** split_on_delim(char* input_text,char delim){
    assert(input_text!=NULL);
    char** output_text = malloc(sizeof(char*));
    
    int size = 1;
    /*
    char* temp = strtok(input_text,&delim);
    *output_text = temp;
    //*output_text = strtok(input_text,&delim);
    while(temp!=NULL){
    //while(output_text[size-1]!=NULL){
        size++;
        output_text = realloc(output_text,size*sizeof(char*));
        temp = strtok(NULL,&delim);
        output_text[size-1] = temp;
    }
    return output_text;
    */
    //char* temp = strtok(input_text,&delim);
    //*output_text = temp;
    *output_text = strtok(input_text,&delim);
    //while(temp!='\0'){
    while(output_text[size-1]!=NULL){
        size++;
        output_text = realloc(output_text,size*sizeof(char*));
        output_text[size-1] = strtok(NULL,&delim);
    }
    return output_text;
    //*/
}

char**** get_document(char* text) {
    assert(text!=NULL);
    char** paragraphs = split_on_delim(text, '\n');
    //printf("%s\n",*(paragraphs));
    //printf("%s\n",*(paragraphs+1));
    int num_para = 0;
    while(paragraphs[num_para]!=NULL){
        num_para++;
    }
    //printf("%d %d\n",0,num_para);
    char**** doc = malloc((num_para+1)*sizeof(char***));
    doc[num_para] = NULL;
    //int i = 0;
    while(num_para--){
    //while(paragraphs[i]!=NULL){
        //printf("%d %d\n",i,num_para);
        char** sentences = split_on_delim(paragraphs[num_para], '.');
        int num_sent=0;
        while(sentences[num_sent]!=NULL){
           num_sent++;
        }
        doc[num_para] = malloc((num_sent+1)*sizeof(char**));
        doc[num_para][num_sent] = NULL;
        //int j = 0;
        while(num_sent--){
        //while(sentences[num_sent]!=NULL){
            doc[num_para][num_sent] = split_on_delim(sentences[num_sent],' ');
            //j++;
        }
        //i++;
    }
    //printf("%d %c",0,doc[1][1][1][5]);
    return doc;
}
/*
char**** get_document(char* text) {
    assert(text!=NULL);
    int para, sent, word, lett;
    para=sent=word=lett=0;
    char **** doc;
    doc = (char ****)malloc(sizeof(char ***)); // document
    doc[0] = (char ***)malloc(sizeof(char **)); //paragraphs
    doc[0][0] = (char **)malloc(sizeof(char *)); //sentences
    doc[0][0][0] = (char *)malloc(sizeof(char)); //word
    doc[0][0][0] = realloc(doc[0][0][0],2*sizeof(char)); //word

    while(*(text+1)!=0){
        printf("%c",*text);
        switch(*text){
            case ' ':
                word++;
                lett = 0;
                //doc[para-1][sent-1] = realloc(doc[para-1][sent-1],word*sizeof(char*));
            case '.':
                sent++;
                word = 0;
                lett = 0;
                //doc[para-1] = realloc(doc[para-1],sent*sizeof(char**));
            case '\n':
                para++;
                sent = 0;
                word = 0;
                lett = 0;
                //doc = realloc(doc,para*sizeof(char***));
            default:
                doc[para][sent][word] = realloc(doc[para][sent][word],2*sizeof(char));
                doc[para][sent][word][lett] = *text;
                lett++;
        }
        text++;
    }
        if(*text==' '){
            word++;
            doc[para-1][sent-1] = realloc(doc[para-1][sent-1],word*sizeof(char*));
        }else if(*text=='.'){
            sent++;
            word = 1;
            doc[para-1] = realloc(doc[para-1],sent*sizeof(char**));

        }else if(*text=='\n'){
            para++;
            sent = 1;
            word = 1;
            doc = realloc(doc,para*sizeof(char***));
        }

        //lett++;
        //doc[para-1][sent-1][word-1] = realloc(doc[para-1][sent-1][word-1],lett*sizeof(char));
        //doc[para-1][sent-1][word-1][lett-1] = *text;

        text++;
    }
    


    return doc;


}
*/

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}