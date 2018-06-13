type t = Types.frameBase;

include Evaluator.Impl({
  type nonrec t = t;
});

type tagOptions = {
  .
  "url": Js.undefined(string),
  "path": Js.undefined(string),
  "content": Js.undefined(string),
  "_type": Js.undefined(string),
};

[@bs.obj]
external makeTagOptions :
  (
    ~url: string=?,
    ~path: string=?,
    ~content: string=?,
    ~_type: string=?,
    unit
  ) =>
  tagOptions =
  "";

[@bs.send.pipe: t]
external selectOne :
  (~selector: string) => Js.Promise.t(Js.Null.t(ElementHandle.t)) =
  "$";

[@bs.send.pipe: t]
external selectAll :
  (~selector: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$$";

[@bs.send.pipe: t]
external selectXPath :
  (~xpath: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$x";

type selectorOptions = {
  .
  "visible": Js.nullable(bool),
  "hidden": Js.nullable(bool),
  "timeout": Js.nullable(float),
};

[@bs.obj]
external makeSelectorOptions :
  (~visible: bool=?, ~hidden: bool=?, ~timeout: float=?, unit) =>
  selectorOptions =
  "";

/* TODO: waitForFunction */

[@bs.send.pipe: t]
external waitForSelector :
  (string, ~options: selectorOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external waitForXPath :
  (~xpath: string, ~options: selectorOptions=?, unit) =>
  Js.Promise.t(ElementHandle.t) =
  "";

/**
 * selectOneEval(selector, fn, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error.
 */
[@bs.send.pipe: t]
external selectOneEval :
  (string, [@bs.uncurry] (Dom.element => 'r)) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(selector, fn, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error. `fn` must return a promise.
 */
[@bs.send.pipe: t]
external selectOneEvalPromise :
  (string, [@bs.uncurry] (Dom.element => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEval(selector, fn, arg1, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error.
 */
[@bs.send.pipe: t]
external selectOneEval1 :
  (string, [@bs.uncurry] ((Dom.element, 'a) => 'r), 'a) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(selector, fn, arg1, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error. `fn` must return a promise.
 */
[@bs.send.pipe: t]
external selectOneEvalPromise1 :
  (string, [@bs.uncurry] ((Dom.element, 'a) => Js.Promise.t('r)), 'a) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval2 :
  (string, [@bs.uncurry] ((Dom.element, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise2 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval3 :
  (string, [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise3 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval4 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise4 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c, 'd) => Js.Promise.t('r)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$eval";

/**
 * selectAllEval(selector, fn)
 * Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`.
 */
[@bs.send.pipe: t]
external selectAllEval :
  (string, [@bs.uncurry] (Dom.nodeList => 'r)) => Js.Promise.t('r) =
  "$$eval";

/** Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`. `fn` must return a promise.
 * */
[@bs.send.pipe: t]
external selectAllEvalPromise :
  (string, [@bs.uncurry] (Dom.nodeList => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$$eval";

/**
 * selectAllEval1(selector, fn, arg1)
 * Runs document.querySelectorAll in the page and passes the result as the
 * first argument to `fn`. It passes `arg1` as the second argument to `fn`.
 */
[@bs.send.pipe: t]
external selectAllEval1 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), 'a) => Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise1 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), Js.Promise.t('a)) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval2 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise2 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval3 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise3 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval4 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise4 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => Js.Promise.t('r)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external addScriptTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe: t]
external addStyleTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe: t]
external click :
  (string, ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] external content : t => Js.Promise.t(string) = "";

[@bs.send.pipe: t]
external focus : (~selector: string) => Js.Promise.t(unit) = "";

/**
 * Fetches the first element matching `selector`, scrolls it into view if not
 * already visible, then hovers over the center of the element using
 * [Page.mouse]. Throws an error if no element matches `selector`.
 */
[@bs.send.pipe: t]
external hover : (~selector: string) => Js.Promise.t(unit) = "";

/**
 * Selects options in a `<select>` tag. Triggers a `change` and `input` event
 * once all the provided options have been selected. If there's no `<select>`
 * element matching selector it throws an error.
 */
[@bs.send.pipe: t]
external select :
  (~selector: string, ~values: array(string)) => Js.Promise.t(array(string)) =
  "";

[@bs.send.pipe: t]
external tap : (~selector: string) => Js.Promise.t(unit) = "";

type typeOptions = {. "delay": float};

[@bs.send.pipe: t]
external type_ :
  (string, string, ~options: typeOptions=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send] external url : t => string = "";
