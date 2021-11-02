# include "my_header.h"


// https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/

vector<short> divide_conquer(vector<short> input_sequence) {
    // Ask if the input comes empty
    if (input_sequence.empty())
        // The input is empty, therefore we cannot do anything so we return that same empty sequence
        return input_sequence;

    // The sequence has elements, therefore subsequences

    // Necessary for loop stop conditions
    short input_length = input_sequence.size();

    // Necessary to find the greatest sum subsequence that will be returned
    short maxSum = SHRT_MIN;
    vector<short> maxSequence;

    // Will hold possible subsequences
    vector<short> currentSequence;
    short currentSum;

    // Starts the search for the greatest sum subsequence
    for (short i = 0; i < input_length; i++){
        // Tells the first element (position) of this subsequence

        for (short j = i; j < input_length; j++){
            // Tells the length of this subsequence

            // Variables needed to calculate the summation of this subsequence are cleaned
            currentSum = 0;
            currentSequence.clear();

            for (short k = i; k <= j; k++){
                // Sums each value of the array
                currentSum += input_sequence.at(k);
                currentSequence.push_back(input_sequence.at(k));
            }

            // Ask if we found a greater summation subsequence
            if (currentSum > maxSum){
                maxSum = currentSum;
                maxSequence = currentSequence;
            }
        }
    }

    // Returns the subsequence with the greatest subsequence
    return maxSequence;
}


vector<short> dynamic_programming(vector<short> input_sequence) {
    // Ask if the input comes empty
    if (input_sequence.empty())
        // The input is empty, therefore we cannot do anything so we return that same empty sequence
        return input_sequence;

    // The sequence has elements, therefore subsequences

    // Necessary for loop stop conditions
    short input_length = input_sequence.size();

    // Necessary to find the greatest sum subsequence that will be returned
    short maxSum;
    vector<short> maxSequence;

    // Will hold possible subsequences
    vector<short> currentSequence;
    short currentSum;

    // Variables needed for memoization
    vector<vector<vector<short>>> table;
    vector<vector<short>> currentLine;

    // Starts the search for the greatest sum subsequence

    // Takes the very first element
    maxSum = input_sequence[0];  // At the start, the very first element is the biggest found
    maxSequence.push_back(maxSum);  // At the start, the biggest found sequence found is the one that only contains the first element

    currentSum = maxSum;
    currentSequence.push_back(currentSum);

    currentLine.push_back(currentSequence);

    // Continues filling the subsequences that take the first element with the pre-known information
    for (short i=1; i < input_length; i++){
        currentSum += input_sequence.at(i);
        currentSequence.push_back(input_sequence.at(i));

        currentLine.push_back(currentSequence);

        if (currentSum > maxSum){
            maxSum = currentSum;
            maxSequence = currentSequence;
        }
    }

    table.push_back(currentLine);

    // Fills the next line eliminating the first elements and using dynamic programming
    for (short i = 1; i < input_length; i++){
        // Moves between lines
        currentLine.clear();
        vector<vector<short>> previous_line = table[i-1];

        // Variables needed to calculate the summation of this subsequence are cleaned
        currentSum = 0;
        currentSequence.clear();

        short previous_length = previous_line.size();

        for (short j = 1; j < previous_length; j++){
            // Fills with subsequences this line
            currentSequence = vector<short>(previous_line[j].begin() + 1, previous_line[j].end());
            currentSum += previous_line[j][j];

            currentLine.push_back(currentSequence);


            // Ask if we found a greater summation subsequence
            if (currentSum > maxSum){
                maxSum = currentSum;
                maxSequence = currentSequence;
            }
        }

        table.push_back(currentLine);
    }


    return maxSequence;

}