### Index
vector, profile, MAUT, 

### Information Filtering
Aka search  
We spend time indexing everything, and then users with a query can quickly find things. Indexing assumed people would want things equally. Indexing needs to go beyond search terms, however. We also need context for quality, useful results.  
We can build a model of your preferences from the set of items you've consumed or liked. 
We have a vector of attributes for a user and each like or dislike you express will either reinforce or diminish the attribute.  
```
Luke: [action: 2, sci-fi: 3, romance: 1]
Movie1: [1, 0, 1]
Movie2: [1, 1, 0]

dot(Luke, Movie1) = 1*2 + 0*3 + 1*1 = 3
dot(Luke, Movie2) = 1*2 + 1*3 + 0*1 = 5

Therefore, Movie2 works better
```
Some drawbacks of this method include new items that can't be well-represented by the existing attributes. It also doesn't take into account movies that are more romantic than others. It also doesn't work well for novelty. It assumes that your preferences for attributes are independent (maybe I only like Romance + Action but not Romance by itself).  

MAUT (multi-attribute utility theory): You like certain combinations of attributes but not others.  

### Case Based Recommender
Create a network of items using a similarity/distance function and then just exploring that network to find what you might like. 

### Knowledge Based Recommender
Did not use pre-existing knowledge and instead uses use interaction to create recommendations from scratch. "Entree" is a restaurant recommender that would recommend based on one restaurant that you want similar to. Then it allowed you to adjust the distance function by tweaking attributes like price, fanciness, traditional/exotic, etc. Uses rules that tell you how to navigate based on new information. Each session was thrown out afterwards. 

### Information Filtering in Detail
- Not all documents are equal
- TFIDF (term frequency inverse document frequency) which looks at the frequency of a term over the frequency of the term over the document set (# of documents / # of documents with the term). This prioritizes unique key words that are central to the document; it is optimizing for a term that occurs *a lot* in one document but it actually pretty rare in others. 
- Terms like "neuro" are better fitting than "the" which is a *stopword*
- Stemming is when we get rid of prefixes and suffixes to get to the essence of the word. This works well in some languages but not in others.
- Phrase identification is when some words have significance together. 
- Search engine optimization is when people try to game the system to get more views
- The vector space model cannot tell the difference between frequency and importance

### Interaction

### Questions
If we filter by what you like then how do we avoid confirmation bias?  
Attibutes also need to be standardized.  
Could you get novelty by looking at trends in how attributes are moving over time?  
The same flaws exist in trying to communicate likes and dislikes to a person, but we use examples; "I like sci-fi, like Star Wars!" And now that we have an example, we can combine the other attributes of Star Wars and reinforce those combinations.  
How do we normalize ratings across different vectors?