import helpers
from operator import itemgetter
from itertools import groupby
from functools import reduce
from dateutil.parser import parse


def determineSentiment(tweets, positives, negatives):
    # create word dictionairies
    positiveDict = {word: 0 for word in positives}
    negativeDict = {word: 0 for word in negatives}

    # determine setiment for word
    def determineWordSentiment(word):
        return 1 if word in positiveDict else -1 if word in negativeDict else 0

    # determine sentiment for tweet
    def determineTweetSentiment(tweet):
        return sum([determineWordSentiment(word) for word in set(tweet)])

    # determine sentiment for all tweets
    return [determineTweetSentiment(tweet) for tweet in tweets]


def classify(tweets, positives, negatives):
    """
    classify all tweets in filename
    prints the number of tweets classified as either
    positive / negative / neutral
    """
    # determine setiment for all tweets
    sentiments = determineSentiment(tweets, positives, negatives)

    # count tweet sentiment
    def counter(acc, sentiment):
        return ({**acc, "positive": acc["positive"] + 1} if sentiment > 0 else
                {**acc, "neutral": acc["neutral"] + 1} if sentiment == 0 else
                {**acc, "negative": acc["negative"] + 1})
    counts = reduce(counter, sentiments, {"positive": 0, "neutral": 0, "negative": 0})

    # print classified counts
    print("Trump's tweets classified:")
    print("    positive: {}".format(counts["positive"]))
    print("    negative: {}".format(counts["negative"]))
    print("    neutral : {}".format(counts["neutral"]))


def positive_word(tweets, positives):
    """prints the top 5 most used positive words"""
    # create word dictionairies
    positiveDict = {word: 0 for word in positives}

    # count the positive words in tweets
    def countWord(word):
        if word in positiveDict:
            positiveDict[word] += 1
    [countWord(word) for tweet in tweets for word in tweet]

    # sort the words
    sortedWords = sorted(positiveDict.items(), key=itemgetter(1), reverse=True)

    # print the 5 most used words
    print("Trump's top 5 most used positive words:")
    for i in range(5):
        print("    {:8s}: {}".format(sortedWords[i][0], sortedWords[i][1]))


def bad_days(dates, tweets, positives, negatives):
    """
    prints all days that trump
    tweeted more negatively than positively
    """
    # determine setiment for all tweets
    sentiments = determineSentiment(tweets, positives, negatives)

    # create grouped sentiments by day
    groupedSentiments = groupby(sorted(zip(dates, sentiments), key=lambda tweet: parse(tweet[0])), itemgetter(0))

    # detemine sentiment for a single day
    def determineDaySentiment(acc, sentiment):
        return [acc[0], acc[1] + (1 if sentiment[1] > 0 else 0 if sentiment[1] == 0 else -1)]

    # detemine sentiments for all days
    daySentiments = [reduce(determineDaySentiment, list(day[1]), [day[0], 0]) for day in groupedSentiments]

    # print bad days
    print("Trump's bad days:")
    [print("   ", day[0]) for day in daySentiments if day[1] < 0]


if __name__ == "__main__":
    # get the dates and tweets from tweet_filename
    dates, tweets = helpers.read_tweets("trump.txt")

    # get the lists of negative and positive words
    positives = helpers.read_words("positive_words.txt")
    negatives = helpers.read_words("negative_words.txt")

    classify(tweets, positives, negatives)
    positive_word(tweets, positives)
    bad_days(dates, tweets, positives, negatives)
