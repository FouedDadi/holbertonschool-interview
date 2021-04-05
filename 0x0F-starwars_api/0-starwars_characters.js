#!/usr/bin/node

const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}/`;
const request = require("request");

request(url, async function (error, res, body) {
  if (res) {
    for (const char of JSON.parse(body).characters) {
      const result = await new Promise((resolve, reject) => {
        request(char, (err, result, body) => {
          if (result) {
            resolve(JSON.parse(body).name);
          }
        });
      });
      console.log(result);
    }
  }
});
