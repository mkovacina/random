This is sample code to add a key to a json object when only the partial path exists.  

Turns out that Newtonsoft.Json doesn't do this for you automatially.

Example:

You start with 
{
  "a":{
    "b":{
      "c":{}
    }
  }
}

And you want to insert node "f":"data" at path "a:b:c:d:e"

You end with
{
  "a": {
    "b": {
      "c": {
        "d": {
          "e": {
            "f": "encrypted string"
          }
        }
      }
    }
  }