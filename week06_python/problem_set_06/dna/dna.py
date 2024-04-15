import csv
from sys import argv


def main():

    # Check for command-line usage
    if len(argv) != 3:
        print("Usage: python ./dna.py DATABASE SEQUENCE")
        return 1

    database_file = argv[1]
    sequence_file = argv[2]

    # Read database file into a variable
    database = list()
    with open(database_file, "r") as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames[1:]
        for i in reader:
            database.append(i)

    # print(strs)
    # print(database)

    # Read DNA sequence file into a variable
    with open(sequence_file, "r") as file:
        sequence = file.read()

    # print(sequence)

    # Find longest match of each STR in DNA sequence
    strs_count = dict()
    for str in strs:
        strs_count[str] = longest_match(sequence, str)

    # print(strs_count)

    # Check database for matching profiles
    for person in database:
        match = True

        for str in strs:
            if int(person[str]) != strs_count[str]:
                match = False
                break

        if match:
            print(person["name"])
            return 0

    print("No match")


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
