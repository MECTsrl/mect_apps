import React, { Component } from 'react';
import { version } from '../package.json';
import './page100.css';
import {MECTdate, MECTtime, MECTlabel} from './MECTplugins';


class Page100 extends Component {

  constructor(props) {
    super(props);

    this.updateData = this.updateData.bind(this);
    this.on_INPUT_clicked = this.on_INPUT_clicked.bind(this);
    this.doWrite = this.doWrite.bind(this);

    this.state = {
        theHEARTBEAT : 0,
        theLED : 0,
        theBUTTON : 0,
        msg : ""
    };
    this.axios = require('axios');
  }

  componentDidMount() {
    this.updateInterval = setInterval(this.updateData, 500 );
  }

  updateData() {
        let thisPage = this;

        //    root@mect /local/flash/root$ cat /tmp/update_all.json
        //    Content-Type: application/json; charset=UTF-8
        //
        //    {
        //    "theHEARTBEAT" :510,
        //    "theLED"       :0,
        //    "theBUTTON"    :1
        //    }

        this.axios.get("/webmi/update_all.cgi", { }, { timeout: 400 })
            .then(function (response) {
                let tmpHEARTBEAT = 0;
                let tmpLED = 0;
                let tmpBUTTON = 0;

                tmpHEARTBEAT = response.data.theHEARTBEAT;
                tmpLED = response.data.theLED;
                tmpBUTTON = response.data.theBUTTON;

                thisPage.setState({
                    theHEARTBEAT : tmpHEARTBEAT,
                    theLED : tmpLED,
                    theBUTTON : tmpBUTTON,
                    msg: "update_all OK"
                });
            })
            .catch(function (error) {
                thisPage.setState({
                    theHEARTBEAT: -1,
                    theLED: 0,
                    theBUTTON: 0,
                    msg: "update_all ERROR"
                });
            });
  }

    componentWillUnmount() {
        clearInterval(this.updateInterval);
    }

    doWrite(params) {
        let thisPage = this;

        this.axios.get("/webmi/do_write.cgi", params, { timeout: 400 })
        .then(function (response) {
            thisPage.setState({ msg: "do_write OK " + response.data });
        })
        .catch(function (error) {
            thisPage.setState({ msg: "do_write ERROR " + error.message });
        });
    }

    on_INPUT_clicked() {
        if (this.state.theLED) {
                this.doWrite({ params: {theLED: 0} });
        } else {
                this.doWrite({ params: {theLED: 1} });
        }
    }

    render() {
        //    const renderValues = this.state.values.map(function(value, i) {
        //        return <li className="p-values">#{i}={value}</li>
        //    });
        //        <p className="p-values">{this.state.actualValue}</p>
        //        <p className="p-values">values=</p>
        //            <ol>{renderValues}</ol>

        return <div>
        <p className="p-barra">
        &nbsp; <button className="demo">HTML5 React JS</button>
        &nbsp; <button className="heartbeat">{this.state.theHEARTBEAT}</button>
        &nbsp; <button className={(this.state.theBUTTON)?"button-1":"button-0"}>{(this.state.theBUTTON)?"red ON":"red off"}</button>
        &nbsp; <button className={(this.state.theLED)?"led-1":"led-0"} onClick={this.on_INPUT_clicked}> {(this.state.theLED)?"blu ON":"blu off"} </button>
        &nbsp; {this.state.msg}
        <br/><video controls preload="auto" autoplay="true" loop width="100%" muted>
            <source src="/webmi/video.mp4" type="video/mp4"/>
            Your browser does not support the video tag.
        </video>
        </p>
        </div>;
    }
}

export default Page100;
