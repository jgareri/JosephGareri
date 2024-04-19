;; Problem1.clj
;; Joseph Gareri
;; 00099183
;; jgareri@my.athens.edu
;; Asg 08 | Prob. 1
;; Turtle Code Referenced: https://github.com/unclebob/turtle-graphics

(ns core
  (:require [clojure.core.async :as async]
            [quil.core :as q]
            [quil.middleware :as m]))

(def channel (async/chan 10))

(defn make []
  {:pos [0 0]
   :pendown? true
   :heading 0
   :lines []})

(defn turn [turtle angle]
  (update turtle :heading #(mod (+ % angle) 360)))

(defn pen [turtle upOrDown]
  (assoc turtle :pendown? (if (= upOrDown 1) true false)))

(defn move [turtle units]
  (let [direction [(Math/cos (Math/toRadians (:heading turtle)))
                   (Math/sin (Math/toRadians (:heading turtle)))]
        movement [(-> units (* (first direction)) int)
                  (-> units (* (second direction)) int)]
        new-pos (mapv + (:pos turtle) movement)]
    (if (:pendown? turtle)
      (-> turtle
          (assoc :pos new-pos)
          (update :lines conj [(:pos turtle) new-pos]))
      (assoc turtle :pos new-pos))))

(defn draw-state [{:keys [turtle]}]
  (q/background 240)
  (q/stroke 0)
  (doseq [line (:lines turtle)]
    (apply q/line (mapcat identity line))))

(defn update-state [{:keys [turtle channel] :as state}]
  (if-let [command (async/poll! channel)]
    (let [cmd (first command)
          args (rest command)]
      (case cmd
        "forward" (assoc state :turtle (move turtle (first args)))
        "turn" (assoc state :turtle (turn turtle (first args)))
        "pen" (assoc state :turtle (pen turtle (first args)))
        state))
    state))

(defn setup []
  {:turtle (make)
   :channel channel})

(defn -main [& args]
  (q/defsketch core
    :title "Turtle Graphics"
    :size [500 500]
    :setup setup
    :update update-state
    :draw draw-state
    :middleware [m/fun-mode])
  args)

;; Interpreter
(defn run-commands [commands]
  (async/thread
    (doseq [cmd commands]
      (async/>! channel cmd)
      (Thread/sleep 1000))))

(def commands [["forward" 100] ["turn" 90] ["forward" 100] ["pen" 0] ["forward" 100] ["pen" 1] ["forward" 100]])

(defn -main [& args]
  (-main)
  (run-commands commands))