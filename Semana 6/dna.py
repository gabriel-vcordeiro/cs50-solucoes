import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv)!= 3:
        print("Missing command-line argument.")
        sys.exit(1)
    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        db = list(reader)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        sequence = file.read()
    # TODO: Find longest match of each STR in DNA sequence
    long_match = []
    for i in range(1,len(db[0])):
    # Comparando arquivo da sequência com cada um da database
        long_match.append(longest_match(sequence,db[0][i]))
    # TODO: Check database for matching profiles
    suspect = 'No Match'
    suspect_counter = 0

    ##Começa a busca: primeiro inicia um que vai por toda a db, e depois pela tabela de matches.
    for i in range(1, len(db)):
        for j in range(len(long_match)):
            #special note, the database is all strings, so int() is required to
            #convert from string to int
            ##long_match[j] igual a db[i][j+1]: acontece porque o campo nome existe, então é sempre um a mais.
            if long_match[j] == int(db[i][j+1]):
                suspect_counter += 1
        ##Suspect counter = número de STRS que cumpriu correto, se bater 3 é o mesmo.
        if suspect_counter == len(long_match):
            # We've got the suspect!  No need to continue.
            ##campo 0 é o nome
            suspect = db[i][0]
            break
        else:
            suspect_counter = 0
    print(suspect)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
