#include <stdio.h>
#include <string.h>

const char *morse[55] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-." };
const char ascii[55] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', '\'', '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"', '$', '@' };

void help(char *msg);

const char find_char(const char *word);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    help("Morse text not found. ERROR_CODE: 1");
    return 1;
  } else if (strcmp(argv[1], "--help") == 0) {
    help("");
    return 0;
  }
  char b[] = "   ";
  char *start = argv[1];
  char *delim;
  do {
    delim = strstr(start, b);
    char re = 0;
    if (delim) {
      *delim = '\0';
      re = 1;
    }

    const char dlm[] = " ";
    const char *morse_words = strtok(start, dlm);

    while (morse_words)
    {
      char ch = find_char(morse_words);
      printf("%c", ch);
      morse_words = strtok(NULL, dlm);
    }

    if (re == 1) {
      *delim = ' ';
    }
    if (delim) {
      printf(" ");
      start = delim + 3;
    }
  } while (delim);

  printf("\n");
}

void help(char *msg)
{
  if (strcmp(msg, "") != 0) {
    printf("%s\n\n", msg);
  }
  printf("Usage: md [morse-text]\n");
  printf("Decode the morse text\n");
}

const char find_char(const char *m_word)
{
  int i;
  for (i = 0; i < 50; i++) {
    if (!strcmp(morse[i], m_word)) {
      return ascii[i];
    }
  }
  return ' ';
}

