// subject.js

class Subject {
  constructor() {
    this.observers = [];
  }

  addObserver(observer) {
    this.observers.push(observer);
  }

  removeObserver(observer) {
    this.observers = this.observers.filter(obs => obs !== observer);
  }

  notifyObservers(news) {
    this.observers.forEach(observer => observer.update(news));
  }
}

module.exports = Subject;
