import React, { Component } from 'react';
import './App.css';

import Page100 from './page100';

class App extends Component {

  constructor(props) {
    super(props);
    this.enterFullScreen = this.enterFullScreen.bind(this);
    this.state = {
      started: false,
      currentPage: "page100",
    };
  }

  enterFullScreen() {
    var elem = document.getElementById("root");
    
    if (elem.mozRequestFullScreen) {
	    console.log("mozRequestFullScreen");
        elem.mozRequestFullScreen();
    } else if (elem.webkitRequestFullScreen) {
	    console.log("webkitRequestFullScreen");
        elem.webkitRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT);
    } else {
	    console.log("no way to enterFullScreen");
    }
    this.setState({ started : true });
  }

  render() {
    // if (!this.state.started) {
    //     return <div className="App">
    //         	<button className="start-button" onClick={this.enterFullScreen}>START WebMI</button>
    //             </div>;
    // } else {
    //     return <div><Page100 /></div>;
    // }
    return <div><Page100 /></div>;
  }
}

export default App;
