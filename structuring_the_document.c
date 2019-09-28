#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
typedef struct document document;
typedef struct paragraph paragraph;
typedef struct sentence sentence;
typedef struct word word;

struct document get_document(char* text) {
    assert(text!=NULL);
    document doc;
    doc.data = malloc(sizeof(paragraph));
    doc.data[0].data = malloc(sizeof(sentence));
    doc.data[0].data[0].data = malloc(sizeof(word));
    doc.data[0].data[0].data[0].data = malloc(sizeof(char));
    doc.data[0].data[0].data[0].data = NULL;
        
    int p,s,w,c;
    
    doc.paragraph_count = p = 0;
    doc.data[0].sentence_count = s = 0;
    doc.data[0].data[0].word_count = w = 0;
    c=0;
    while(*text!='\0'){
        if(*text=='\n'){
            //New Paragraph
            p++;
            doc.data = realloc(doc.data,(p+1)*sizeof(paragraph));
            doc.paragraph_count=p+1;
            s=0;
            w=0;
            c=0;        
            doc.data[p].data = malloc(sizeof(sentence));
            doc.data[p].data[s].data = malloc(sizeof(word));
            doc.data[p].data[s].data[w].data = malloc(sizeof(char));
            doc.data[p].data[s].data[w].data = NULL;
            //printf("%s\n","Beet");
        }else if (*text=='.') {
            //New Sentence
            //w++;
            s++;
            doc.data[p].data = realloc(doc.data[p].data,(s+1)*sizeof(sentence));
            doc.data[p].sentence_count = s;
            w=0;
            c=0;
            doc.data[p].data[s].data = malloc(sizeof(word));
            doc.data[p].data[s].data[w].data = malloc(sizeof(char));
            doc.data[p].data[s].data[w].data = NULL;
        }else if (*text==' ') {
            //New word
            w++;
            doc.data[p].data[s].data = realloc(doc.data[p].data[s].data,(w+1)*sizeof(word));
            doc.data[p].data[s].data[w].data = malloc(sizeof(char));
            doc.data[p].data[s].data[w].data = NULL;        
            doc.data[p].data[s].word_count = w+1;
            c=0;
            //printf("%s\n","Yeet");
        }else{
            doc.data[p].data[s].data[w].data = realloc(doc.data[p].data[s].data[w].data,(c+2)*sizeof(char));
            doc.data[p].data[s].data[w].data[c] = *text;
            doc.data[p].data[s].data[w].data[c+1] = '\0';
            //printf("%c\n",doc.data[p].data[s].data[w].data[c]);
            c++;
        }
        text++;
    }
    //printf("%c\n",doc.data[0].data[0].data[0].data[0]);
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}