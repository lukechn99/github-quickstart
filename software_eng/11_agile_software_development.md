# Agile Software Development
Also called rapid development is now the standard among companies and radically reduces the time needed for development.  
One great thing is that there is no hierarchy in agile. This also makes some people uncomfortable because it means they don't know their place with regards to others.  
Agile is nice because it allows you to discard things when not needed.  

### User stories vs PBI
User stories are about the persona. It allows us to focus on the user. PBI's need the task and the estimated effort that it needs. But a user story is a dynamic narrative that is created collaboratively with the user. From that, PBIs are extracted and prioritized by the product owner.  
Persona's should state what they want and why they want it. There should be no ambiguity; if any of those questions are not understood, then you should work with the user to rewrite the story. We break down the user story into epics which are overarching goals.  
Only once the epic has been created to be finished within a sprint and everyone agrees on the acceptance criteria/definition of done. A detailed story will need 3-5 acceptance criteria.  
While some PBI stories come from the user stories, others can just be non-functional requirements that you come up with or dependencies that are separate and do not come from users.  
**User stories are not technical**, the technical stuff comes from the acceptance criteria. Definition of done is fairly consistent and remains the same. 
  
[Roman Pichler](https://www.romanpichler.com/wp-content/redirects/Persona-Template.pdf)'s Persona Template
```
/--------------------------------|--------------------------------|--------------------------------\
| Picture and Name               | Details                        | Goals                          |
|--------------------------------|--------------------------------|--------------------------------|
| What does the persona look     | What are the persona’s relevant| What problem does the persona  |
| like? What is its name? Choose | characteristics and behaviours?| want to solve or which benefit |
| a realistic and believable     | For instance, demographics,    | does the character seek? Why   |
| picture and name.              | such as age, gender,           | would the persona want to use  |
|                                | occupation, and income;        | or buy the product?            |
|                                | psychographics, including      |                                |
|                                | lifestyle, social class, and   |                                |
|                                | personality; and behavioural   |                                |
|                                | attributes like usage patterns,|                                |
|                                | attitudes, and brand loyalty.  |                                |
|                                | Only list relevant details.    |                                |
\--------------------------------|--------------------------------|--------------------------------/
```  

### PBI (Product Backlog Item)
```
Story Name
Value Statement (paragraph form)
Acceptance Criteria (what is required for the business and product owner to accept the finished story?
Definition of Done (what is required by the team before sending out for review? This should be the same for all stories; it's more of an overall "team goal")
Effort Size Estimate (I've previously used 1pt = 2 hours)
PBI Authors
```
When working on PBIs and stories, prioritize quality over quantity; it is better to get the top priority done and nothing else than to finish 5 non-essential tasks. 

### Example
```
Prompt
Election officials need another type of voting algorithm. They want to be able to determine a single winner based on the
candidate receiving the most ballots with a fair coin toss if there is a tie or ties between candidates. This will be called
Popularity Only (PO).
```  

```
User story
As an election official, I need to be able to run a Popularity Only election
```
This story can be one single PBI. The acceptance criteria could be that it can fairly run the popularity algorithm. 
