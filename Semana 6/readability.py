from cs50 import get_string
def index(letters, sentences, words):
    l = letters/words * 100
    s = sentences/words * 100
    index = 0.0588 * l - 0.296 * s - 15.8
    index = round(index)
    if index>=16:
        print("Grade 16+")
    elif index> 1 and index<17:
        print(f"Grade {index}")
    else:
        print("Before Grade 1\n")
letras = 0
sentencas = 0
palavras = 1
text = get_string("Insert the text:")
for i in range (len(text)):
    if text[i].isalpha():
        letras += 1
    elif text[i].isspace():
        palavras += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentencas += 1
index(letras,sentencas,palavras)
