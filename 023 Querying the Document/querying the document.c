#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {

	return(document[n-1][m-1][k-1]);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 

	return(document[m-1][k-1]);
}

char*** kth_paragraph(char**** document, int k) {

	return(document[k-1]);
}

char **string_divider(char *str,int *divisions_counter,char *divisor_caracters){

  char *dv_ptr;
  char **divided_str =(char**)malloc(1001*sizeof(char*));
  dv_ptr = strtok (str,divisor_caracters);
  *divided_str=dv_ptr;
  int i=1;
  while (dv_ptr != NULL)
  {
    dv_ptr = strtok (NULL, divisor_caracters);
    if(dv_ptr == NULL){
   
    	break;
    }
    *(divided_str+i)=dv_ptr;
    i++;
  }
  divided_str = realloc(divided_str,i*sizeof(char*));
  *divisions_counter=i;
  return(divided_str);
}

char**** get_document(char* text) {

	assert(text!=NULL);

	int *n =malloc(sizeof(int));
	int paragraphs, *sentences, **words;
	char *temp_ptr;
	char ****document = (char****)malloc(sizeof(char***));
	
	document = (char****)string_divider(text,n,"\n");
	
	paragraphs = *n;

	sentences = (int*)malloc(paragraphs*sizeof(int));
	words=(int**)malloc(paragraphs*sizeof(int*));
	
	for(int i=0;i<paragraphs;i++){
	
		temp_ptr = (char*)document[i];
		document[i]=(char***)string_divider(temp_ptr,n,".");
		*(sentences+i) = *n;
	}
	
	for(int i=0;i<paragraphs;i++){
	
		words[i]=(int*)malloc(sentences[i]*sizeof(int));
	}
	
	for(int i=0;i<paragraphs;i++){
	
		for (int j=0;j<sentences[i];j++){
		
			temp_ptr=(char*)document[i][j];
			document[i][j]=string_divider(temp_ptr,n," ");
			words[i][j] = *n;
		}
	
	}
	free(words);
	free(sentences);
	free(n);
	
  return(document);

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
