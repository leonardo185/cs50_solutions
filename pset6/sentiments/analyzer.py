import nltk

class Analyzer():
    """Implements sentiment analysis."""
    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        # TODO
        #This line stores the positive words in a list.
        self.positives = []
        with open("positive-words.txt","r") as pwords:
            for line in pwords:
                if line.startswith(";") and line.startswith(""):
                    pass
                else:
                    self.positives.extend(line.split())

        #This line stores the negative words in a list.
        self.negatives = []
        with open("negative-words.txt","r") as nwords:
            for line in nwords:
                if line.startswith(";") and line.startswith(""):
                    pass
                else:
                    self.negatives.extend(line.split())

    def analyze(self,text):
        """Analyze text for sentiment, returning its score."""
        # TODO
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0

        for token in tokens:
            if token in self.positives:
                score+=1
            elif token in self.negatives:
                score-=1

        return score

