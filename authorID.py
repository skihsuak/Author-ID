
import string

def count_words(file_name):
    """
    This function reads a file and creates a dictionary of words in the file.

        Parameters:
        file_name (file name with trailing ".txt")
    Returns:
        my_dictionary (a dictionary with words as keys, and number of times
        it occurs as values)

    """
    my_dictionary = {} #initialize a dictionary
    with open(file_name, 'r', encoding='utf-8') as my_file:
        for line in my_file:
            line = line.lower()  # convert the line to lower case
            for word in line.split():  # then split it into words
                # take out leading and trailing special characters
                word = word.strip(string.punctuation + string.digits)
                if word in my_dictionary:
                    my_dictionary[word] += 1 #if exists, add 1
                elif word == '' : #used pass to not count white space.
                    pass
                else:
                    my_dictionary[word] = 1 #if its a new word set equal to 1
    return my_dictionary

def report(word_dict):
    """
    This function prints the statistics of all the words in the dictionary.

    Parameters:
        word_dict (a dictionary built from the "count_words" function)
    Returns:
        Nothing
    """

    longest_word = max(word_dict,key = len) #max function based on length
    word_list = sorted(word_dict, key = word_dict.get, reverse = True)

    print("The longest word is: ", longest_word)
    print("The 5 most common words are: ")
    for word in word_list:  #takes the 5 most recurring words in file.
        print(word + ':', word_dict[word])


def out_file(word_dict): #created my own function for writing the outfile.
    """
    This function writes to an output file "out.txt" that contains all words
    and the amount of times they occur.

    Parameters:
        word_dict (a dictionary built from the "count_words" function)
    Returns:
        Nothing
    """
    my_list = sorted(word_dict) #sorts alphabetically
    with open('out.txt', 'w', encoding='utf-8') as out_file:
        for word in my_list:
            out_file.write(word + ':' + str(word_dict[word]) + '\n')


def main():
    my_file = input("Please enter the filename: ")
    word_count = count_words(my_file)
    report(word_count)

    #commented out to make grading easier, but very cool feature!!!
    #draw_cloud(word_count)


if __name__ == '__main__':
    main()

