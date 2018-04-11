import React, { Component } from 'react';
import './MECTplugins.css';

class MECTdate extends Component {

    constructor(props) {
      super(props);
      this.updateData = this.updateData.bind(this);
      this.state = {
          value : "YYYY-MM-DD"
      };
    }

    componentDidMount() {
        this.updateInterval = setInterval(this.updateData, 1000);
    }

    updateData() {
        let now = new Date();
        let date = now.getFullYear() + "-";
        let month = 1 + now.getMonth();
        if (month < 10)
            date += "0";
        date += month + "-" + now.getDate();
        this.setState({ value : date });
    }

    componentWillUnmount() {
        clearInterval(this.updateInterval);
    }

    render() {
        return <span className="MECTdate-style">{this.state.value}</span>;
    }
}

class MECTtime extends Component {

    constructor(props) {
        super(props);
        this.updateData = this.updateData.bind(this);
        this.state = {
            value : "HH:MM:SS"
        };
    }

    componentDidMount() {
        this.updateInterval = setInterval(this.updateData, 1000);
    }

    updateData() {
        let now = new Date();
        let time = now.getHours() + ":" + now.getMinutes() + ":" + now.getSeconds();
        this.setState({ value : time });
    }

    componentWillUnmount() {
        clearInterval(this.updateInterval);
    }

  render() {
        return <span className="MECTtime-style">{this.state.value}</span>;
  }
}

class MECTlabel extends Component {

    constructor(props) {
        super(props);
        this.updateData = this.updateData.bind(this);
        this.state = {
            value : "12345678"
        };
    }

    componentDidMount() {
        this.updateInterval = setInterval(this.updateData, 1000);
    }

    updateData() {
        let now = new Date();
        this.setState({ value : (now % 1000)});
    }

    componentWillUnmount() {
        clearInterval(this.updateInterval);
    }

  render() {
        return <span className="MECTtime-style">{this.state.value}</span>;
  }
}

export {MECTdate, MECTtime, MECTlabel};
